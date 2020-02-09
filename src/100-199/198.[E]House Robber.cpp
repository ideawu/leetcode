#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 回溯型动态规划问题, 但不用缓存每一个入口的结果, 只需要缓存前2个.
***********************************************************/
int rob(vector<int>& nums) {
	int a=0, b=0;
	int m = 0;
	for(int i=0; i<nums.size(); i++){
		m = max(m, a + nums[i]);
		a = b;
		b = m;
	}
	return m;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,2,3,1};
	printf("%d\n", rob(nums));
	nums = {2,7,9,3,1};
	printf("%d\n", rob(nums));
	return 0;
}

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/
