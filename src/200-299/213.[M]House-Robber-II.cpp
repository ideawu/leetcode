#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 回溯型动态规划问题.
* 关键点在于处理最后一个时, 要避免同时包含第1个和最后一个.
***********************************************************/
int rob(vector<int>& nums) {
	if(nums.size() == 1) return nums[0];
	int ret = 0;
	int a = 0, b = 0;
	bool fa = true, fb = false; // 是否包含第1个
	for(int i=0; i<nums.size(); i++){
		int n = nums[i];
		if(i == nums.size()-1){
			if(!fa){
				ret = max(ret, n+a);
			}
			break;
		}
		
		int c = n + a;
		bool fc;
		if(c > ret){
			// 包含当前
			fc = fa;
			ret = c;
		}else if(c < ret){
			// 不包含当前
			fc = fb;
		}else{
			// 如果相等, 优先选择不包含第1个的方案, 这样有包含最后一个
			fc = (a && b);
		}
		
		a = b;
		b = ret;
		fa = fb;
		fb = fc;
	}
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {2,3,2};
	printf("%d\n", rob(nums));
	nums = {1,2,3,1};
	printf("%d\n", rob(nums));
	return 0;
}

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/
