#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 做减法后, 二查找余数.
* 找 upper_bound, 遍历时跳过后面重复的元素.
***********************************************************/
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> ret(2);
	for(int i=0; i<nums.size(); i++){
		if(i > 0 && nums[i] == nums[i-1]) continue;
		
		// upper_bound(t)
		int t = target - nums[i];
		int s = 0, e = nums.size();
		while(s < e){
			int m = s + (e-s)/2;
			if(nums[m] <= t){
				s = m + 1;
			}else{
				e = m;
			}
		}
		// auto it = std::upper_bound(nums.begin(), nums.end(), t);
		// int e = it - nums.begin();
		if(e > 0 && nums[e-1] == t && (e-1) != i){
			ret[0] = i + 1;
			ret[1] = e-1 + 1;
			break;
		}
    }
	return ret;
}

vector<int> twoSum2(vector<int>& nums, int target) {
	vector<int> ret(2);
	unordered_map<int,int> vars;
	for(int i=0; i<nums.size(); i++){
		if(i > 0 && nums[i] == nums[i-1]) continue;
		int t = target - nums[i];
		if(vars.count(t) > 0){
			ret[0] = i + 1;
			ret[1] = vars[t] + 1;
			break;
		}
		vars[nums[i]] = i;
    }
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {2,7,11,15};
	print_array(twoSum(nums, 9));
	nums = {2,2,2,4,5,5,5,7,11,15};
	print_array(twoSum(nums, 10));
	nums = {2,2,2,4,5,7,11,15};
	print_array(twoSum(nums, 10));
	nums = {2,7,11,15};
	print_array(twoSum2(nums, 9));
	
	return 0;
}

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/
