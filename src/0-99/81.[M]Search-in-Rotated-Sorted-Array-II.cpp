#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 将数组平分成两半, 那么可以判断至少一半是有序的.
* 对有序的一半进行二分查找, 对另一半继续进行平分.
* 因为有重复元素, 所以无法通过头尾元素比较判断是否有序, 怎么办?
* 	不下判断, 继续递归. 最坏的情况是 O(n)
***********************************************************/
bool searchHelper(vector<int>& nums, int s, int e, int t) {
	if(nums[s] < nums[e]){
		while(s <= e){
			int m = s + (e-s)/2;
			if(nums[m] == t){
				return true;
			}
			if(nums[m] < t){
				s = m + 1;
			}else{
				e = m - 1;
			}
		}
		return false;
	}
	int m = s + (e-s)/2;
	bool a = searchHelper(nums, s, m, t);
	if(a){
		return true;
	}
	return searchHelper(nums, m+1, e, t);
}

bool search(vector<int>& nums, int t) {
	return searchHelper(nums, 0, nums.size()-1, t);
}

int main(int argc, char **argv){
	return 0;
}

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/
