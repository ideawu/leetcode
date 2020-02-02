#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这是一道图遍历题.
* 注意图的节点可以重复处理(元素重复使用)
***********************************************************/
void helper(vector<vector<int>> &ret, vector<int> &nums, int s, int target, vector<int> &pre){
	if(target == 0){
		ret.push_back(pre);
		return;
	}
	for(int i=s; i<nums.size(); i++){
		int n = 0;
		while(1){ // 元素可重复使用
			int t = target - nums[i] * (n+1);
			if(t < 0){
				break;
			}
			n ++;
			pre.push_back(nums[i]);
			helper(ret, nums, i+1, t, pre);
		}
		while(--n >= 0){
			pre.pop_back();
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ret;
	vector<int> pre;
	helper(ret, candidates, 0, target, pre);
	return ret;
}

int main(int argc, char **argv){
	vector<int> candidates;
	int target;
	vector<vector<int>> ret;

	candidates = {1,2,3};
	target = 4;
	ret = combinationSum(candidates, target);
	print_matrix(ret);

	// candidates = {4,1,2};
	// target = 32;
	// ret = combinationSum(candidates, target);
	// print_matrix(ret);
		
	candidates = {2,3,6,7};
	target = 7;
	ret = combinationSum(candidates, target);
	print_matrix(ret);
		
	printf("\n");
	candidates = {2,3,5};
	target = 8;
	ret = combinationSum(candidates, target);
	print_matrix(ret);
	
	return 0;
}

/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
