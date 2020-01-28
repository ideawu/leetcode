#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 采用分而治之递归穷举的方法.
* 在递归函数中传递交易次数上限.
* 优化: 记录 close_list, 避免重复计算, 注意是否缓存与 mt 相关.
***********************************************************/
int maxProfitHelper(vector<int>& prices, int s, int mt, vector<int> &close_list) {
	if(mt == 1){
		if(close_list[s] != -1){
			return close_list[s];
		}
	}
	int mp = 0;
	for(int j=s+1; j<prices.size(); j++){
		int p = prices[j] - prices[s];
		if(p > 0){
			if(mt > 1){
				p += maxProfitHelper(prices, j+1, mt-1, close_list);
			}
			mp = max(mp, p);
		}
	}
	if(mt == 1){
		close_list[s] = mp;
	}
	return mp;
}

int maxProfit(vector<int>& prices) {
	vector<int> close_list(prices.size(), -1);
    int mp = 0;
	for(int i=0; i<prices.size(); i++){
		int p = maxProfitHelper(prices, i, 2, close_list);
		mp = max(mp, p);
	}
	return mp;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {3,3,5,0,0,3,1,4};
	printf("%d\n", maxProfit(nums));
	nums = {1,2,3,4,5};
	printf("%d\n", maxProfit(nums));
	nums = {7,6,4,3,1};
	printf("%d\n", maxProfit(nums));
	return 0;
}

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
