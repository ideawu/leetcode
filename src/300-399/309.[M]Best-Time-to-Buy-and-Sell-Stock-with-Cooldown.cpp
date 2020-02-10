#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 回溯型动态规划. 算是穷举的一种.
* 这类问题, 限交易次数比不限交易次数难.
***********************************************************/
int maxProfit(vector<int>& prices) {
	int ret = 0;
	vector<vector<int>> dp(prices.size(), {0, 0});
	for(int i=0; i<prices.size(); i++){
		int buy = 0;
		int sell = 0;
		for(int j=0; j<i; j++){
			// leave at 1 for cooldown
			if(j < i-1){
				// sell at [j], then buy at [i]
				buy = max(buy, dp[j][1]);
			}
			// buy at [j], then sell at [i]
			if(prices[i] > prices[j]){
				sell = max(sell, dp[j][0] + prices[i] - prices[j]);
			}
		}
		dp[i][0] = buy;
		dp[i][1] = sell;
		ret = max(ret, max(buy, sell));
	}
	return ret;
}

/***********************************************************
# 解题思路

* 找上升沿, 分别在最高点[i]和次高点[i-1]卖, 分别收益是 p1, p2.
* 以两种状态, 进行下一步. 以 [i+1] 和 [i+2] 进行买入.
* 如果连续两天下跌, 则把之前在次高点卖的交易修正为也在最高点卖.
***********************************************************/
int maxProfit2(vector<int>& prices) {
	int sum1 = 0, sum2 = 0;
	
	int buy_idx1 = 0;
	int buy_idx2 = 0;
	int sell_idx1 = 0;
	int sell_idx2 = 0;
	
	for(int i=1; i<prices.size(); i++){
		// 阶段高点
		if(i == prices.size() - 1 || (prices[i-1] <= prices[i] && prices[i] > prices[i+1])){
			sell_idx1 = i;
			sell_idx2 = (i == prices.size() - 1)? i : i-1;
			// printf("buy  %d %d\n", buy_idx1, buy_idx2);
			// printf("sell %d %d\n", sell_idx1, sell_idx2);
			
			int p1 = prices[sell_idx1] - prices[buy_idx1];
			int p2 = prices[sell_idx2] - prices[buy_idx2];
			sum1 += p1;
			sum2 += p2;
			
			buy_idx1 = sell_idx1 + 2;
			buy_idx2 = sell_idx2 + 2;
			
			// corner case
			if(buy_idx1 >= prices.size()){
				break;
			}
			continue;
		}
		
		// 如果高点之后连续两天下跌, 则把之前在次高点卖的交易修正为也在最高点卖.
		if(i == sell_idx1 + 2 && prices[i] <= prices[i-1] && prices[i-1] <= prices[i-2]){
			sum2 += prices[sell_idx1] - prices[sell_idx2];
			
			buy_idx1 = i;
			buy_idx2 = i;
			continue;
		}
		
		if(i > sell_idx1 + 2){
			if(prices[i] < prices[i-1]){
				buy_idx1 = i;
				buy_idx2 = i;
			}
		}
	}
	return max(sum1, sum2);
}

int main(int argc, char **argv){
	vector<int> nums = {1,2,3,0,2};
	printf("%d\n", maxProfit(nums));
	printf("%d\n", maxProfit2(nums));
	return 0;
}

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/
