#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 先试一试递归穷举. 加缓存.
***********************************************************/
unordered_map<int, int> cache;
int integerBreak(int n) {
	if(n <= 2) return 1;
	if(cache.count(n)){
		return cache[n];
	}
	int ret = 0;
	for(int i=3; i<=n; i++){
		for(int j=1; j<n; j++){
			int k = n - j;
			int r = max(j, integerBreak(j)) * k;
			ret = max(ret, r);
		}
	}
	cache[n] = ret;
	return ret;
}

/***********************************************************
# 解题思路

* 用动态规划(回溯).
* 是一个全量引用的规划, 没法用滑动窗口.
***********************************************************/
int integerBreak2(int n) {
	vector<int> dp(n+1, 1);
	for(int i=3; i<=n; i++){
		for(int j=1; j<i; j++){
			int k = i - j;
			int r = max(j, dp[j]) * k;
			dp[i] = max(dp[i], r);
		}
	}
	return dp[n];
}

/***********************************************************
# 解题思路

* 用动态规划(推导).
* 是一个全量引用的规划, 没法用滑动窗口.
***********************************************************/
int integerBreak3(int n) {
	vector<int> dp(n+1, 1);
	for(int i=2; i<n; i++){
		for(int j=i+1; j<=n; j++){
			int k = j - i;
			int r = max(i, dp[i]) * k;
			dp[j] = max(dp[j], r);
		}
	}
	return dp[n];
}

int main(int argc, char **argv){
	printf("%d\n", integerBreak(2));
	printf("%d\n", integerBreak(10));
	printf("%d\n", integerBreak(58));
	printf("%d\n", integerBreak2(2));
	printf("%d\n", integerBreak2(10));
	printf("%d\n", integerBreak2(58));
	printf("%d\n", integerBreak3(2));
	printf("%d\n", integerBreak3(10));
	printf("%d\n", integerBreak3(58));
	return 0;
}

/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
*/
