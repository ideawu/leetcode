#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

int main(int argc, char **argv){
	return 0;
}

/***********************************************************
# 解题思路

* 因为是已排序数据, 所以很直接就想到二分查找.
* 但是, 怎么二分?
***********************************************************/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
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
