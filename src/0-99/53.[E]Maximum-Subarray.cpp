#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 1. 穷举法
* 2. 动态规划
* 题目建议的分而治之, 确实非常不明显, 没想出来.
***********************************************************/
int maxSubArrayBrute(vector<int>& nums) {
	int tm = -INT_MAX;
	for(int i=0; i<nums.size(); i++){
		int s = nums[i];
		int m = s;
		for(int j=i+1; j<nums.size(); j++){
			s += nums[j];
			m = max(m, s);
		}
		tm = max(tm, m);
    }
	return tm;
}

int maxSubArray(vector<int>& nums) {
	int m = -INT_MAX;
	for(int i=1; i<nums.size(); i++){
		nums[i] = max(nums[i] + nums[i-1], nums[i]);
		m = max(m, nums[i]);
	}
	return m;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {-2,1,-3,4,-1,2,1,-5,4};
	printf("%d\n", maxSubArrayBrute(nums));
	printf("%d\n", maxSubArray(nums));
	return 0;
}

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
