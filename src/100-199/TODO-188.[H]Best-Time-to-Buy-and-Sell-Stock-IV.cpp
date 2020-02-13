#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 用穷举法.
* 以任何一个点开始作为买点, 找到第一个卖点. 然后对剩下的数据进行递归.
* 通过缓存来优化, 缓存 key 的编码: k+src.
***********************************************************/
int cnt;
int helper(int k, vector<int> &prices, int s, unordered_map<int,int> &cache){
	cnt ++;
	if(k == 0 || s >= prices.size()-1) return 0;
	int cache_key = (k << 16) + s; // assume s < (2<<17), that's true
	if(cache.count(cache_key)){
		return cache[cache_key];
	}
	
	int maxp = 0;
	for(int i=s; i<prices.size()-1; i++){
		int buy = prices[i];
		for(int j=i+1; j<prices.size(); j++){
			int sell = prices[j];
			int p = sell - buy;
			if(p > 0){
				p += helper(k-1, prices, j+1, cache);
				maxp = max(maxp, p);
			}
		}
	}
	
	cache[cache_key] = maxp;
	return maxp;
}
int maxProfit(int k, vector<int>& prices) {
	cnt = 0;
	unordered_map<int,int> cache;
	return helper(k, prices, 0, cache);
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {2,4,1};
	printf("%d\n", maxProfit(2, nums));
	printf("cnt: %d\n", cnt);
	nums = {3,2,6,5,0,3};
	printf("%d\n", maxProfit(2, nums));
	printf("cnt: %d\n", cnt);
	return 0;
}

/*
Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/
