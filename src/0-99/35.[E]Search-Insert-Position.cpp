#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 就是实现 lower_bound
***********************************************************/
int searchInsert(vector<int>& nums, int target) {
	int s = 0;
	int e = nums.size();
	while(s < e){
		int m = s + (e-s)/2;
		if(nums[m] < target){
			s = m + 1;
		}else{
			e = m;
		}
	}
	return s;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,3,5,6};
	printf("%d\n", searchInsert(nums, 5));
	nums = {1,3,5,6};
	printf("%d\n", searchInsert(nums, 2));
	nums = {1,3,5,6};
	printf("%d\n", searchInsert(nums, 7));
	nums = {1,3,5,6};
	printf("%d\n", searchInsert(nums, 0));
	return 0;
}

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/
