#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 因为是已排序数据, 所以很直接就想到二分查找.
* 但是, 怎么二分? 事实上不能二分, 如果陷入这样想, 那就解不出来了.
* 这道题只能一次排除一行或者一列, 无法排除一半(二分).
* 总是和左下角元素比较, 决定排除行还是列.
***********************************************************/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	int i = m - 1;
	int j = 0;
	while(1){
		if(j >= n || i < 0) return false;
		if(matrix[i][j] == target) return true;
		if(matrix[i][j] < target){
			j ++;
		}else{
			i --;
		}
	}
}

int main(int argc, char **argv){
	vector<vector<int>> matrix;
	matrix = {
	  {1,   4,  7, 11, 15},
	  {2,   5,  8, 12, 19},
	  {3,   6,  9, 16, 22},
	  {10, 13, 14, 17, 24},
	  {18, 21, 23, 26, 30}
	};
	printf("%d\n", searchMatrix(matrix, 5));
	printf("%d\n", searchMatrix(matrix, 20));
	return 0;
}

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
