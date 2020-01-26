#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 用递归来解
* 对于每一个元素 arr[i], t = t - arr[i], 然后再递归
* 如何体现元素重复使用?
* 优化空间:
***********************************************************/
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ret;
	return ret;
}

int main(int argc, char **argv){
	vector<int> candidates;
	int target;
	vector<vector<int>> ret;
		
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
* 如果对源数据排序, 那么在生成过程中避免重复, 结果集不需要去重.
* 关键点在于, 生成组合的过程, 虽然每一次元素可以多次使用, 但递归过程
*	不能对源数据集回溯(已使用过的要排除), 否则无法避免重复,
*	这一点非常重要! 为什么?
*/

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
