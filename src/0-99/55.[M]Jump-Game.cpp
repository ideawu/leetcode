#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这个题目属于能量可转移的按顺序分段处理类型
* 使用动态规划
* 按顺序处理各分段
* 前一个分段的剩余能量转移到下一个分段
* 注意, 转移的能量不能叠加到后面, 而是取较大者(转移函数)
***********************************************************/
bool canJump(vector<int>& nums) {
	int p = 0;
	for(int i=0; i<nums.size()-1; i++){
		p = max(nums[i], p-1);
	}
	return p > 0;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {2,3,1,1,4};
	printf("%d\n", canJump(nums));
	nums = {3,2,1,0,4};
	printf("%d\n", canJump(nums));
	return 0;
}

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/
