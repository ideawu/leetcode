#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 图遍历.
* 其实是一道求k个元素组合的题.
* 解题的出发点是求子集(subsets).
* 不用预先生成数组, 只需要传递 [s,e] 即可.
* 优化点: 1, 如果剩余的元素数量小于k则不递归; TODO: 大 sum 快速判断
* Space Complexity: O(n) 递归栈和 pre, 返回的结果不算占用.
***********************************************************/
void helper(vector<vector<int>> &ret, int s, int e, int k, int n, vector<int> &pre){
	if(k == 0){
		if(n == 0){
			ret.push_back(pre);
		}
		return;
	}
	for(int i=s; i<=e-k+1; i++){
		pre.push_back(i);
		helper(ret, i+1, e, k-1, n-i, pre);
		pre.pop_back();
	}
}
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> ret;
	vector<int> pre;
	helper(ret, 1, 9, k, n, pre);
	return ret;
}

int main(int argc, char **argv){
	print_matrix(combinationSum3(3, 7));
	print_matrix(combinationSum3(3, 9));
	return 0;
}

/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
