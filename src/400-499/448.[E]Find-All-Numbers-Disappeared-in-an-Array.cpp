#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这是一道数组归位的题.
* 遍历一趟, 不断交换错位的元素直到元素归位.
* 如果交换目标相等, 丢弃当前元素.
***********************************************************/
vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> ret;
	for(int i=0; i<nums.size(); i++){
		// // 直观思维
		// while(nums[i] != i+1){
		// 	if(nums[i] == nums[nums[i]-1]){
		// 		break;
		// 	}
		// 	std::swap(nums[i], nums[nums[i]-1]);
		// }
		// 逆向思维 
		while(nums[i] != nums[nums[i]-1]){
			std::swap(nums[i], nums[nums[i]-1]);
		}
	}
	for(int i=0; i<nums.size(); i++){
		if(nums[i] != i+1){
			ret.push_back(i+1);
		}
	}
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums = {4,3,2,7,8,2,3,1};
	vector<int> ret = findDisappearedNumbers(nums);
	print_array(ret);
	return 0;
}

/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
