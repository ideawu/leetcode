#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 图遍历穷举.
***********************************************************/
void helper(vector<vector<int>> &ret, vector<int> &nums, int s, vector<int> &pre){
	for(int i=s; i<nums.size(); i++){
		pre.push_back(nums[i]);
		ret.push_back(pre);
		helper(ret, nums, i+1, pre);
		pre.pop_back();
	}
}
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> ret;
	vector<int> pre;
	ret.push_back(pre);
	helper(ret, nums, 0, pre);
	return ret;
}
/***********************************************************
# 解题思路

* 树遍历穷举.
***********************************************************/
void helper2(vector<vector<int>> &ret, vector<int> &nums, int s, vector<int> &pre){
	if(s == nums.size()){
		return;
	}
	
	helper2(ret, nums, s+1, pre);
	
	pre.push_back(nums[s]);
	ret.push_back(pre);
	helper2(ret, nums, s+1, pre);
	pre.pop_back();
}
vector<vector<int>> subsets2(vector<int>& nums) {
	vector<vector<int>> ret;
	vector<int> pre;
	ret.push_back(pre);
	helper2(ret, nums, 0, pre);
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums = {1, 2, 3};
	vector<vector<int>> ret;
	ret = subsets(nums);
	print_matrix(ret);
	ret = subsets2(nums);
	print_matrix(ret);
	return 0;
}

/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
