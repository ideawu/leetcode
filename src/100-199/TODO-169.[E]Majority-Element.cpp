#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 只需要找出现次数最多的元素即可.
***********************************************************/
int majorityElement(vector<int>& nums) {
	int m=0, mv=INT_MIN;
	unordered_map<int, int> count;
	for(auto n : nums){
		count[n] ++;
		if(count[n] > mv){
			m = n;
			mv = count[n];
		}
	}
    return m;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {3,2,3};
	printf("%d\n", majorityElement(nums));
	nums = {2,2,1,1,1,2,2};
	printf("%d\n", majorityElement(nums));
	return 0;
}

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
