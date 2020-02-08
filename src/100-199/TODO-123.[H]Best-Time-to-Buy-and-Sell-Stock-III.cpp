#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 采用分而治之递归穷举的方法.
* 在递归函数中传递交易次数上限.
* 优化: 记录 cache, 避免重复计算, 注意是否缓存与 mt 相关.
***********************************************************/
int helper(vector<int>& prices, int s, int mt, vector<int> &cache) {
	if(mt == 0) return 0;
	if(mt == 1){
		if(cache[s] != -1){
			return cache[s];
		}
	}
	int mp = 0;
	for(int i=s; i<prices.size()-1; i++){
		for(int j=i+1; j<prices.size(); j++){
			int p = prices[j] - prices[i];
			if(p > 0){
				p += helper(prices, j+1, mt-1, cache);
				mp = max(mp, p);
			}
		}
	}
	if(mt == 1){
		cache[s] = mp;
	}
	return mp;
}

int maxProfit(vector<int>& prices) {
	vector<int> cache(prices.size(), -1);
	return helper(prices, 0, 2, cache);
}

/***********************************************************
# 解题思路

* 将序列按峰值拆分成两个区间, 两个区间有区间内的最大收益之和 sum.
* 求划分方案使 sum 最大化.
* 两趟遍历, 第一趟找出全序列 lmin, lmax;
* 第二趟反向遍历找到右区间 rmin, rmax, 同时更新 lmin, lmax.
***********************************************************/
int maxProfit2(vector<int>& prices) {
	return 0;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {3,3,5,0,0,3,1,4};
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
