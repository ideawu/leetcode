#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 纯粹调剂气氛用的 Easy 题, 做就是了. 但是, 别做错了!
***********************************************************/
vector<int> plusOne(vector<int>& digits) {
}

int main(int argc, char **argv){
	vector<int> nums;
	
	nums = {1,2,3};
	nums = plusOne(nums);
	print_array(nums);

	nums = {4,3,2,1};
	nums = plusOne(nums);
	print_array(nums);

	nums = {9};
	nums = plusOne(nums);
	print_array(nums);
	
	return 0;
}

/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
