#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 使用循环归位算法.
* 当出现重复时, 将错位的一个标记为 -1, 避免它被再次交换到别的位置.
***********************************************************/
vector<int> findDuplicates(vector<int>& nums) {
	vector<int> ret;
	for(int i=0; i<nums.size(); i++){
		while(1){
			if(nums[i] == -1){
				break;
			}
			if(nums[i] == i + 1){
				break;
			}
			int idx = nums[i] - 1;
			if(nums[i] == nums[idx]){
				ret.push_back(nums[i]);
				nums[i] = -1;
				break;
			}
			swap(nums[i], nums[idx]);
		}
	}
	return ret;
}

/***********************************************************
# 解题思路

* 使用标记归位算法.
* 如果目标位元素是正数, 将其转为负数.
***********************************************************/
vector<int> findDuplicates2(vector<int>& nums) {
	vector<int> ret;
	for(int i=0; i<nums.size(); i++){
		if(nums[i] == i + i){
			continue;
		}
		int idx = abs(nums[i]) - 1;
		if(nums[idx] < 0){
			ret.push_back(abs(nums[i]));
		}else{
			nums[idx] *= -1;
		}
	}
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {4,3,2,7,8,2,3,1};
	print_array(findDuplicates(nums));
	nums = {4,3,2,7,8,2,3,1};
	print_array(findDuplicates2(nums));
	return 0;
}

/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/
