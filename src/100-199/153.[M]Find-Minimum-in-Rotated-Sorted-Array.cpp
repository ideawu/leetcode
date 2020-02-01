#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 将数组分成两段, 至少有一段是有序的. 取有序那段的最小值.
* 继续二分.
***********************************************************/
int helper(vector<int> &nums, int s, int e){
	if(s == e) return nums[s];
	int m = s + (e-s)/2;
	if(nums[s] < nums[m]){
		return min(nums[s], helper(nums, m+1, e));
	}else{
		return min(nums[m+1], helper(nums, s, m));
	}
}
int findMin(vector<int>& nums) {
    return helper(nums, 0, nums.size()-1);
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {3,4,5,1,2};
	printf("%d\n", findMin(nums));
	nums = {4,5,6,7,0,1,2};
	printf("%d\n", findMin(nums));
	return 0;
}

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/
