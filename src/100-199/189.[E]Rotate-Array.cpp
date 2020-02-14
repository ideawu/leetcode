#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 借用链表旋转的思路.
* 取模之后, 看末尾有 k 几个元素被旋转到了左边, 然后翻转 k, 再翻转 n-k.
***********************************************************/
void rotate(vector<int>& nums, int k) {
	k = k % nums.size();
	std::reverse(nums.begin(), nums.end());
	std::reverse(nums.begin(), nums.begin() + k);
	std::reverse(nums.begin() + k, nums.end());
}

int main(int argc, char **argv){
	vector<int> nums = {1,2,3,4,5,6,7};
	// print_array(nums);
	for(int i=1; i<12; i++){
		vector<int> s = nums;
		rotate(s, i);
		print_array(s);
	}
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
