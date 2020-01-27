#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 直观上, 旋转 90 度可以变成两个 180 度翻转操作: 上下翻转和斜对角转置.
* 理论上, 应该可以用矩阵变换推导出来.
***********************************************************/
void rotate(vector<vector<int>>& matrix) {
	int m = matrix.size();
    std::reverse(matrix.begin(), matrix.end());
	for(int i=0; i<m; i++){
		for(int j=i+1; j<m; j++){
			std::swap(matrix[i][j], matrix[j][i]);
		}
	}
}

int main(int argc, char **argv){
	vector<vector<int>> matrix;
	
	matrix.clear();
	matrix.push_back({1,2,3});
	matrix.push_back({4,5,6});
	matrix.push_back({7,8,9});
	rotate(matrix);
	print_matrix(matrix);
	
	matrix.clear();
	matrix.push_back({ 5, 1, 9,11});
	matrix.push_back({ 2, 4, 8,10});
	matrix.push_back({13, 3, 6, 7});
	matrix.push_back({15,14,12,16});
	rotate(matrix);
	print_matrix(matrix);
	
	return 0;
}

/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/
