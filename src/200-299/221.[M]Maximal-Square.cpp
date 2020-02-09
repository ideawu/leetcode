#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 扫描, 并修改输入数据.

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
***********************************************************/
int maximalSquare(vector<vector<int>>& matrix) {
}

/***********************************************************
# 解题思路

***********************************************************/
int maximalSquare2(vector<vector<int>>& matrix) {
	int ret = 0;
    int m = matrix.size();
	int n = matrix[0].size();
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(matrix[i][j] == 0){
				continue;
			}
			
		}
	}
	return ret;
}


int main(int argc, char **argv){
	vector<vector<int>> matrix;
	matrix.push_back({1,0,1,0,0});
	matrix.push_back({1,0,1,1,1});
	matrix.push_back({1,1,1,1,1});
	matrix.push_back({1,0,0,1,0});
	
	vector<vector<int>> m;
	m = matrix;
	printf("%d\n", maximalSquare(m));
	m = matrix;
	printf("%d\n", maximalSquare2(m));
	
	return 0;
}

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/
