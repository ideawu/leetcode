#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 思路是渐进式穷举.
* 取出第0个元素, 然后再穷举剩下的.
* 取出第1个元素, 然后再穷举剩下的.
* ...
* 因为是数组, 可以把"取"操作变为与头元素交换后再取头元素.
***********************************************************/
void helper(vector<vector<int>> &ret, vector<int>& nums, int s, vector<int> &pre){
	if(s == nums.size()){
		ret.push_back(pre);
		return;
	}
	for(int i=s; i<nums.size(); i++){
		std::swap(nums[s], nums[i]);
		pre.push_back(nums[s]);
		helper(ret, nums, s+1, pre);
		pre.pop_back();
		std::swap(nums[s], nums[i]);
	}
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ret;
	vector<int> pre;
	helper(ret, nums, 0, pre);
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,2,3};
	print_matrix(permute(nums));
	return 0;
}

/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
