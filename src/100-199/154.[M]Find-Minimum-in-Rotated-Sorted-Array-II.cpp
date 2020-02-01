#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 因为可能有重复元素, 所以二分后, 可能两段都无法确定有序.
* 最坏的情况, 递归n次, 时间复杂度是 O(n).
***********************************************************/
int helper(vector<int> &nums, int s, int e){
	if(s == e) return nums[s];
	int m = s + (e-s)/2;
	int l, r;
	if(nums[s] < nums[m]){
		l = nums[s];
	}else{
		l = helper(nums, s, m);
	}
	if(nums[m+1] < nums[e]){
		r = nums[m+1];
	}else{
		r = helper(nums, m+1, e);
	}
	return min(l, r);
}
int findMin(vector<int>& nums) {
    return helper(nums, 0, nums.size()-1);
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,3,5};
	printf("%d\n", findMin(nums));
	nums = {2,2,2,0,1};
	printf("%d\n", findMin(nums));
	return 0;
}

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/
