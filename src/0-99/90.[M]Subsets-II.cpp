#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 首先, 对输入集进行排序, 这样通过特定的生成算法, 生成的子集不会有重复.
* 遇到重复子集时, 取子集0-n个元素与子集之后的元素进行组合.
* 使用跳跃式穷举, 而不是渐进式穷举.
* 当某个元素不是第一个重复元素时, 不进行递归. 因为第一个重复元素的处理
	会把后续的元素包括.
* 这种递归逻辑巧妙地实现了"取子集0-n个元素与子集之后的元素进行组合".
***********************************************************/
void helper(vector<vector<int>> &ret, vector<int> &nums, int s, vector<int> &pre){
	for(int i=s; i<nums.size(); i++){
		if(i > s && nums[i] == nums[i-1]){
			continue;
		}
		pre.push_back(nums[i]);
		ret.push_back(pre);
		helper(ret, nums, i+1, pre);
		pre.pop_back();
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	vector<vector<int>> ret;
	vector<int> pre;
	ret.push_back(pre);
	helper(ret, nums, 0, pre);
	return ret;
}

int main(int argc, char **argv){
	vector<vector<int>> ret;
	vector<int> nums = {1,2,2};
	ret = subsetsWithDup(nums);
	print_matrix(ret);
	return 0;
}

/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
