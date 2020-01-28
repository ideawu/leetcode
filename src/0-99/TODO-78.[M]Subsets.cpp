#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

***********************************************************/
vector<vector<int>> subsets(vector<int>& nums) {
}

int main(int argc, char **argv){
	vector<int> nums = {1, 2, 3};
	vector<vector<int>> ret = subsets(nums);
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
