#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

***********************************************************/
int maximalRectangle(vector<vector<char>>& matrix) {

}

int main(int argc, char **argv){
	return 0;
}

/*
解题思路也许可以暴力破解, 然后再进行优化.

不过, 可以把二维空间的问题简化成一维空间之后, 再利用"84.Largest-Rectangle-in-Histogram"的解法来解决.

从 n = 1 开始, 前 n 行的每一列组成一个单位矩形(要求第 n 行的值不为 0, 即矩形不能悬空, 因为悬空的情况已经处理过了), 问题就转化成 84 号问题了.

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/
