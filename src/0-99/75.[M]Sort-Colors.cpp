#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这是一道 partition 题, 因为结果集有3个数. 用3个指针: lo, mi, hi.
* 根据 arr[mi] 的值, 决定与 lo, hi 交换还是 mi ++
* arr[lo] == 0, lo++
* arr[hi] == 2, hi--
* lo 不能超越 mi, 所以 lo++ 时, mi=max(mi, lo)
	特别的, 因为初始时 mi=lo, 所以要么 mi==lo, 要么 arr[lo]=1,
	所以和 lo 交换后 mi++
* 停止条件: mi > hi(注意!)
***********************************************************/
void sortColors(vector<int>& nums) {
    int lo = 0;
	int mi = 0;
	int hi = nums.size()-1;
	while(mi <= hi){
		if(nums[mi] == 0){
			swap(nums[lo], nums[mi]);
			lo ++;
			mi ++; // mi = max(mi, lo);
		}if(nums[mi] == 1){
			mi ++;
		}else if(nums[mi] == 2){
			swap(nums[mi], nums[hi]);
			hi --;
		}
	}
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {2,0,2,1,1,0};
	sortColors(nums);
	print_array(nums);
	return 0;
}

/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/
