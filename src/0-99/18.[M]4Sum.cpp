#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 求组合.
* 用递归的方式求 n 个数之和. 在函数参数中传递前序路径.
***********************************************************/
void helper(vector<vector<int>> &ret, vector<int> &nums, int s, int target, int count, vector<int> &pre){
	if(count == 0){
		if(target == 0){
			ret.push_back(pre);
		}
		return;
	}
	for(int i=s; i<nums.size()-count+1; i++){
		if(i>s && nums[i] == nums[i-1]) continue;
		pre.push_back(nums[i]);
		helper(ret, nums, i+1, target - nums[i], count-1, pre);
		pre.pop_back();
	}
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	std::sort(nums.begin(), nums.end());
	vector<vector<int>> ret;
	vector<int> pre;
	helper(ret, nums, 0, target, 4, pre);
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums = {1, 0, -1, 0, 0, -2, 2};
	vector<vector<int>> ret = fourSum(nums, 0);
	print_matrix(ret);
	return 0;
}

/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
