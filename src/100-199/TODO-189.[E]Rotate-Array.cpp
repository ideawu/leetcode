#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

***********************************************************/
void rotate(vector<int>& nums, int k) {
    k %= nums.size();
	for(int i=0; i<k; i++){
		swap(nums[i], nums[nums.size()-k+i]);
	}
	print_array(nums);
}

int main(int argc, char **argv){
	vector<int> nums = {1,2,3,4,5,6,7};
	// print_array(nums);
	for(int i=1; i<7; i++){
		vector<int> s = nums;
		rotate(s, i);
	}
	// print_array(nums);
	return 0;
}

/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/
