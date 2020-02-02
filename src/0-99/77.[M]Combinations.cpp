#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 图遍历穷举.
***********************************************************/
void helper(vector<vector<int>> &ret, int n, int s, int k, vector<int> &pre){
	if(k == 0){
		ret.push_back(pre);
		return;
	}
	if(s > n){
		return;
	}
	for(int i=s; i<=n-k+1; i++){
		pre.push_back(i);
		helper(ret, n, i+1, k-1, pre);
		pre.pop_back();
	}
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
	vector<int> pre;
	helper(ret, n, 1, k, pre);
	return ret;
}

/***********************************************************
# 解题思路

* 这种方法比较巧妙, 思路就是类似计数器原理, 按位计数加1, 有进位则操作
	更高的位. 每一位的初始值是高一位的值, 初始化的过程也是一次操作一位.
***********************************************************/
vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> result;
	int i = 0;
	vector<int> p(k, 0);
	while (i >= 0) {
		p[i]++;
		if (p[i] > n) --i;
		else if (i == k - 1) result.push_back(p);
		else {
		    ++i;
		    p[i] = p[i - 1];
		}
	}
	return result;
}

int main(int argc, char **argv){
	print_matrix(combine(4, 2));
	return 0;
}

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
