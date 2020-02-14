#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 非常经典的动态规划问题.
* 单节点引用. 分别用推导和回溯两种方法来解, 练习.
* 状态转移: dp(n) => dp(n+1)+1, dp(n+2)+1, dp(n+5)+1
* 最长推导距离是 max(coins)
***********************************************************/
// 推导型
int coinChange(const vector<int>& coins, int amount) {
	int mc = *std::max_element(coins.begin(), coins.end());
	vector<int> dp(mc+1, -1);
	dp[0] = 0;
	for(int i=0; i<amount; i++){
		if(dp[0] != -1){
			for(int j=0; j<coins.size(); j++){
				int next = coins[j];
				dp[next] = max(dp[next], dp[0] + 1);
			}
		}
		// 窗口移动
		std::copy(dp.begin()+1, dp.end(), dp.begin());
		dp[dp.size()-1] = -1;
	}
	return dp[0];
}

// 回溯型
int coinChange2(const vector<int>& coins, int amount) {
	int mc = *std::max_element(coins.begin(), coins.end());
	vector<int> dp(mc+1, -1);
	dp[0] = 0;
	for(int i=1; i<=amount; i++){
		std::copy(dp.rbegin()+1, dp.rend(), dp.rbegin());
		dp[0] = -1;
		for(int j=0; j<coins.size(); j++){
			int prev = coins[j];
			if(dp[prev] != -1){
				dp[0] = max(dp[0], dp[prev]+1);
			}
		}
	}
	return dp[0];
}

int main(int argc, char **argv){
	printf("%d\n", coinChange({1,2,5}, 11));
	printf("%d\n", coinChange({2}, 3));
	printf("%d\n", coinChange2({1,2,5}, 11));
	printf("%d\n", coinChange2({2}, 3));
	return 0;
}

/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
