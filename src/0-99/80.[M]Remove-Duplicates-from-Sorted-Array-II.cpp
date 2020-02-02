#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 用3个指针遍历. f 指向下一个可放置元素的坐标.
***********************************************************/
int removeDuplicates(vector<int>& nums) {
    int k = 2;
	int p = 0;
	int f = 0;
	for(int n=p+1; n<=nums.size(); n++){
		if(n == nums.size() || nums[p] != nums[n]){
			for(int j=p; j<min(p+k,n); j++){
				nums[f++] = nums[j];
			}
			p = n;
		}
	}
	return f;
}

/***********************************************************
# 解题思路

* 只需要两个指针 f, n, 如果 arr[f-k] != arr[n], 则 arr[f+1]=arr[n].
* f 指向已放置好的元素的坐标.
***********************************************************/
int removeDuplicates2(vector<int>& nums) {
    int k = 2;
	int f = k-1;
	for(int n=f+1; n<nums.size(); n++){
		if(nums[f-k+1] != nums[n]){
			nums[++f] = nums[n];
		}
	}
	return f+1;
}


int main(int argc, char **argv){
	vector<int> nums;
	int len;
	nums = {1,1,1,2,2,3};
	len = removeDuplicates2(nums);
	print_array(nums, len);

	nums = {0,0,1,1,1,1,2,3,3};
	len = removeDuplicates2(nums);
	print_array(nums, len);

	return 0;
}

/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

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
