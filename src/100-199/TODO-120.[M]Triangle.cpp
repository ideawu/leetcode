#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 动态规划, 节点回溯引用计算取最小值.
* 题目希望只用 O(log2 n) 空间, 即树的深度.
* 那就申请深度个元素的数组.
***********************************************************/
int minimumTotal(vector<vector<int>>& triangle) {
}

int main(int argc, char **argv){
	vector<vector<int>> t;
	t.push_back({2});
	t.push_back({3,4});
	t.push_back({6,5,7});
	t.push_back({4,1,8,3});
	printf("%d\n", minimumTotal(t));
	return 0;
}

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
