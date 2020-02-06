#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 注意时间复杂度.
***********************************************************/
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	return false;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,2,3,1};
	printf("%d\n", containsNearbyAlmostDuplicate(nums, 3, 0));
	nums = {1,0,1,1};
	printf("%d\n", containsNearbyAlmostDuplicate(nums, 1, 2));
	nums = {1,5,9,1,5,9};
	printf("%d\n", containsNearbyAlmostDuplicate(nums, 2, 3));
	return 0;
}

/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/
