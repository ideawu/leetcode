#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 采用递归的方法
* 注意要去重
* 因为递归导致要将后一步的结果集与前一步合并, 所以使用辅助函数, 将前一
*	步的结果(路径)传给后一步.
* 关于去重, 有比较 tricky 的地方.
***********************************************************/
int c2 = 0;
void combinationSumHelper(vector<vector<int>> &ret, vector<int> &prev, vector<int>& candidates, int start, int target){
	c2 ++;
	if(start >= candidates.size()){
		return;
	}
	
	int c = candidates[start];
	if(c == target){
		prev.push_back(c);
		// 去重
		if(std::find(ret.begin(), ret.end(), prev) == ret.end()){
			ret.push_back(prev);
		}
	}else if(c > target){
		return;
	}else if(c < target){
		int t = target - c;
		prev.push_back(c);
		combinationSumHelper(ret, prev, candidates, start+1, t);
	}

	prev.pop_back();
	combinationSumHelper(ret, prev, candidates, start+1, target);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ret;
	vector<int> prev;
	std::sort(candidates.begin(), candidates.end());
	combinationSumHelper(ret, prev, candidates, 0, target);
	return ret;
}

// 虽然这种遍历方式是正确的, 但我无法理解为什么要采用此种不直观的遍历方式,
// 它的理论基础是什么?
// 似乎是跳过某些无效的递归调用?
int c3 = 0;
void helper(vector<int>& num, int target, int start, vector<int>& out, vector<vector<int>>& res) {
	c3 ++;
	if (target < 0) return;
	if (target == 0) { res.push_back(out); return; }
	for (int i = start; i < num.size(); ++i) {
	    if (i > start && num[i] == num[i - 1]) continue;
	    out.push_back(num[i]);
	    helper(num, target - num[i], i + 1, out, res);
	    out.pop_back();
	}
}
vector<vector<int>> combinationSum3(vector<int>& num, int target) {
	vector<vector<int>> res;
	vector<int> out;
	sort(num.begin(), num.end());
	helper(num, target, 0, out, res);
	return res;
}

int main(int argc, char **argv){
	vector<int> candidates;
	int target;
	vector<vector<int>> ret;
	
	candidates = {10,1,2,7,6,1,5};
	target = 8;
	ret = combinationSum2(candidates, target);
	print_matrix(ret);
	
	printf("\n");
	
	candidates = {2,5,2,1,2};
	target = 5;
	ret = combinationSum2(candidates, target);
	print_matrix(ret);
	
	printf("\n");
	
	c2 = 0;
	c3 = 0;
	candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	target = 8;
	ret = combinationSum2(candidates, target);
	printf("%d\n", c2);
	ret = combinationSum3(candidates, target);
	printf("%d\n", c3);
	// print_matrix(ret);
	
	return 0;
}

/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
