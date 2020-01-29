#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这是一道求组合的题, 图遍历.
* 通过排序源数据来避免有重复元素.
* 不使用重复子集(基于当前s位置之后, 而不是整个源数据)的非第一个元素.
***********************************************************/
void helper(vector<vector<int>> &ret, vector<int>& nums, int s, int target, vector<int> &pre){
	if(pre.size() == 3){
		if(target == 0){
			ret.push_back(pre);
		}
		return;
	}
	for(int i=s; i<nums.size(); i++){
		if(i > s && nums[i] == nums[i-1]){
			continue;
		}
		int t = target - nums[i];
		pre.push_back(nums[i]);
		helper(ret, nums, i+1, t, pre);
		pre.pop_back();
	}
}
vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
	
	vector<vector<int>> ret;
	vector<int> pre;
	helper(ret, nums, 0, 0, pre);
	return ret;
}

int main(int argc, char **argv){
	vector<vector<int>> ret;
	vector<int> nums;
	nums = {-1, 0, 1, 2, -1, -4};
	ret = threeSum(nums);
	print_matrix(ret);
	return 0;
}

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
