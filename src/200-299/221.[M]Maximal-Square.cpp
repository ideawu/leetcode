#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

1 0 1 0 1
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

* 每个点由: 左上, 左, 上 3 个点来决定.
***********************************************************/
int maximalSquare(vector<vector<int>>& matrix) {
	int w = 0;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<int> dp(n, 0);
	int tl = 0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(matrix[i][j] == 0){
				continue;
			}
			int left = (j==0)? 0 : dp[j-1];
			int top  = dp[j];
			dp[j] = 1 + min(tl, min(left, top));
			w = max(w, dp[j]);
			tl = top;
		}
	}
	return w*w;
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
