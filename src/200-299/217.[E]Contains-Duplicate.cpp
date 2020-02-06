#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

***********************************************************/
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> cnt;
	for(auto n : nums){
		if(++cnt[n] == 2){
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,2,3,1};
	printf("%d\n", containsDuplicate(nums));
	nums = {1,2,3,4};
	printf("%d\n", containsDuplicate(nums));
	nums = {1,1,1,3,3,4,3,2,4,2};
	printf("%d\n", containsDuplicate(nums));
	return 0;
}

/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/
