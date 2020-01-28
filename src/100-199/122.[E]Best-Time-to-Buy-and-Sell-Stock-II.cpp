#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 采用递归穷举的方法
* 依次选定一个元素, 以该元素作为买点, 找到下一个卖点后, 递归剩下的.
* 优化: 因为可能重复计算, 所以将确定的结果存到 close_list, 避免重复计算.
***********************************************************/
int maxProfitHelper(vector<int>& prices, int s, vector<int> &close_list) {
	if(close_list[s] != -1){
		return close_list[s];
	}
	
	int mp = 0;
	for(int j=s+1; j<prices.size(); j++){
		int p = prices[j] - prices[s];
		if(p > 0){
			p += maxProfitHelper(prices, j+1, close_list);
			mp = max(mp, p);
		}
	}
	
	close_list[s] = mp;
	return mp;
}

int maxProfit(vector<int>& prices) {
	vector<int> close_list(prices.size(), -1);
	int mp = 0;
	for(int i=0; i<prices.size(); i++){
		int p = maxProfitHelper(prices, i, close_list);
		mp = max(mp, p);
	}
	return mp;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {7,1,5,3,6,4};
	printf("%d\n", maxProfit(nums));
	nums = {1,2,3,4,5};
	printf("%d\n", maxProfit(nums));
	nums = {7,6,4,3,1};
	printf("%d\n", maxProfit(nums));
	return 0;
}

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
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
