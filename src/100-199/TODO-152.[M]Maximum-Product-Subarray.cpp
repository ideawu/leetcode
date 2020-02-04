#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* a 从第一个元素开始乘, b 从第一个负数的后一个正数开始乘.
***********************************************************/
int maxProduct(vector<int>& nums) {
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {2,3,-2,4};
	printf("%d\n", maxProduct(nums));
	nums = {-2,1,0,-1};
	printf("%d\n", maxProduct(nums));
	nums = {2,3,-2,4,5,-1,-2,-3};
	printf("%d\n", maxProduct(nums));
	return 0;
}

/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
