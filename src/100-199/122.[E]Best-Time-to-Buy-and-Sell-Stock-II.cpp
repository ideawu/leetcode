#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 采用递归穷举的方法
* 依次选定一个元素, 以该元素作为买点, 找到下一个卖点后, 递归剩下的.
* 优化: 因为可能重复计算, 所以将确定的结果存到 cache, 避免重复计算.
***********************************************************/
int helper(vector<int>& prices, int s, vector<int> &cache) {
	if(cache[s] != -1){
		return cache[s];
	}
	
	int ret = 0;
	for(int i=s; i<prices.size()-1; i++){
		for(int j=i+1; j<prices.size(); j++){
			int p = prices[j] - prices[i];
			if(p > 0){
				p += helper(prices, j+1, cache);
				ret = max(ret, p);
			}
		}
	}
	
	cache[s] = ret;
	return ret;
}

int maxProfit(vector<int>& prices) {
	vector<int> cache(prices.size(), -1);
	return helper(prices, 0, cache);
}

/***********************************************************
# 解题思路

* 这道题有一个心智负担, 限制不能在同一时间买和卖. 但先卖后买是可以的.
	是误导型条件(未必要进行卖后买).
* 其实是对差值进行累积.
* 找出所有的上升区间, 在区间开始时买, 结束时卖, 得到阶段性收益.
***********************************************************/
int maxProfit2(vector<int>& prices) {
	if(prices.size() <= 1) return 0;
	int ret = 0;
	int pre = INT_MAX;
	for(auto n : prices){
		ret += max(0, n - pre);
		pre = n;
	}
	// int low = prices[0];
	// for(int i=1; i<prices.size(); i++){
	// 	low = min(low, n);
	// 	if(i == prices.size() - 1 || (prices[i-1] <= prices[i] && prices[i] > prices[i+1])){
	// 		ret += max(0, prices[i] - low);
	// 		low = prices[i];
	// 	}
	// }
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {7,1,5,3,6,4};
	printf("%d\n", maxProfit(nums));
	printf("%d\n", maxProfit2(nums));
	nums = {1,2,3,4,5};
	printf("%d\n", maxProfit(nums));
	printf("%d\n", maxProfit2(nums));
	nums = {7,6,4,3,1};
	printf("%d\n", maxProfit(nums));
	printf("%d\n", maxProfit2(nums));
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
