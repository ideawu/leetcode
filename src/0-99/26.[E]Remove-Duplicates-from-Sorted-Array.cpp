#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 使用前后两个指针进行遍历
* 前指针 n 指向下一个不重复的元素
* 后指针 p 为基准指针, 指向不重复的列表的最后一个元素. 下一个不重复的
*	元素将被插入到 p 之后, 然后 p 后移
* 如果 p 和 n 相邻, 则不做元素插入操作
***********************************************************/
int removeDuplicates(vector<int>& nums) {
	int p = 0;
	for(int n=1; n<nums.size(); n++){
		if(nums[n] == nums[p]){
			continue;
		}else{
			p += 1;
			if(p != n){
				nums[p] = nums[n];
			}
		}
	}
	return p + 1;
}

int main(int argc, char **argv){
	int n;
	vector<int> nums;
	
	nums = {1,1,2};
	n = removeDuplicates(nums);
	print_array(nums, n);
	
	nums = {0,0,1,1,1,2,2,3,3,4};
	n = removeDuplicates(nums);
	print_array(nums, n);

	return 0;
}

/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
	print(nums[i]);
}
*/
