#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 根据行的头节点进行 upper_bound 查找 ub, ub-1 即目标行.
* 对目标行进行二分查找.
* 考察的是 upper_bound() 和 binary_search(), 注意 s<e 和 s<=e.
***********************************************************/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
	int n = matrix[0].size();
	
	// upper_bound of row[0]
	int s = 0;
	int e = m + 1;
	while(s < e){
		int mid = s + (e-s)/2;
		if(matrix[mid][0] > target){
			e = mid;
		}else{
			s = mid + 1;
		}
	}
	int r = s - 1;
	if(r < 0){
		return false;
	}
	
	// binary search
	vector<int> &row = matrix[r];
	s = 0;
	e = n - 1;
	while(s <= e){
		int mid = s + (e-s)/2;
		if(row[mid] == target){
			return true;
		}else if(row[mid] > target){
			e = mid - 1;
		}else{
			s = mid + 1;
		}
	}
	return false;
}

/***********************************************************
# 解题思路

* 把二维数组转化成一维数组(只进行坐标转化), 然后二分查找.
***********************************************************/
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();
	
	int s = 0;
	int e = m * n - 1;
	while(s <= e){
		int mid = s + (e-s)/2;
		int r = mid / n;
		int c = mid % n;
		if(matrix[r][c] == target){
			return true;
		}else if(matrix[r][c] > target){
			e = mid - 1;
		}else{
			s = mid + 1;
		}
	}
	return false;
}

int main(int argc, char **argv){
	vector<vector<int>> matrix;
	
	matrix.clear();
	matrix.push_back({1,   3,  5,  7});
	matrix.push_back({10, 11, 16, 20});
	matrix.push_back({23, 30, 34, 50});
	printf("%d\n", searchMatrix2(matrix, 3));

	matrix.clear();
	matrix.push_back({1,   3,  5,  7});
	matrix.push_back({10, 11, 16, 20});
	matrix.push_back({23, 30, 34, 50});
	printf("%d\n", searchMatrix2(matrix, 13));
	
	return 0;
}

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
