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
	vector<int> nums(triangle.size());
	int ret = triangle[0][0];
	nums[0] = triangle[0][0];
	for(int i=1; i<triangle.size(); i++){
		int mx = INT_MAX;
		int pp = INT_MAX/2; // assume triangle[][] < INT_MAX/2
		for(int j=0; j<=i; j++){
			int p = j==i? INT_MAX/2 : nums[j];
			int v = triangle[i][j];
			int m = min(v+pp, v+p);
			pp = p;
			nums[j] = m;
			mx = min(mx, m);
		}
		ret = mx;
	}
	return ret;
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
