#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 要求时间复杂度是 O(log n), 那就是要用二分查找法.
* 其实就是实现 lower_bound, upper_bound
***********************************************************/
vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> ret = {-1, -1};
    int s = 0;
	int e = nums.size() - 1;
	// lower_bound
	while(s < e){
		int m = s + (e-s)/2;
		if(nums[m] < target){
			s = m + 1;
		}else{
			e = m;
		}
	}
	if(nums[s] != target){
		return ret;
	}
	ret[0] = s;
	
	e = nums.size() - 1;
	// upper_bound
	while(s < e){
		int m = s + (e-s)/2;
		if(nums[m] <= target){
			s = m + 1;
		}else{
			e = m;
		}
	}
	if(nums[s] > target){
		s --;
	}
	ret[1] = s;
	return ret;
}

int main(int argc, char **argv){
	vector<int> r;
	vector<int> nums = {5,7,7,8,8,10};
	r = searchRange(nums, 8);
	print_array(r);
	nums = {5,7,7,8,8,10};
	r = searchRange(nums, 6);
	print_array(r);
	return 0;
}

/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
