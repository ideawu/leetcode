#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 和 46. Permutations 类似, 唯一的区别是, 如果两个数相同, 就不处理了.
***********************************************************/
void helper(vector<vector<int>> &ret, vector<int>& nums, int s, vector<int> &pre){
	if(s == nums.size()){
		ret.push_back(pre);
		return;
	}
	for(int i=s; i<nums.size(); i++){
		if(i > s && nums[i] == nums[s]) continue;
		std::swap(nums[i], nums[s]);
		pre.push_back(nums[s]);
		helper(ret, nums, s+1, pre);
		pre.pop_back();
		std::swap(nums[i], nums[s]);
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ret;
	vector<int> pre;
	helper(ret, nums, 0, pre);
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,1,2};
	print_matrix(permuteUnique(nums));
	nums = {1,2,1};
	print_matrix(permuteUnique(nums));
	return 0;
}

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
