#include <stdio.h>
#include <string>
#include <vector>
#include "../include/util.h"

using namespace std;

void checkNode(vector<vector<int>>& grid, vector<vector<int>>& res, int x, int y, int pc){
	int m = grid.size();
	int n = grid[0].size();
	int cost = grid[x][y];
	res[x][y] = min(res[x][y], pc + cost);
	if(y+1 < n){
		checkNode(grid, res, x, y+1, res[x][y]);
	}
	if(x+1 < m){
		checkNode(grid, res, x+1, y, res[x][y]);
	}
}

// 正向思维, 递归
int minPathSumBrute(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> res(m, vector<int>(n, INT_MAX));
	// ret.assign(m, vector<int>(n, 0));
	checkNode(grid, res, 0, 0, 0);
	// printf("%d\n", res[m-1][n-1]);
	return res[m-1][n-1];
}

// 逆向思维, 回溯(每个cell只有2个parent)
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> res(m, vector<int>(n, INT_MAX));

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			int cost = grid[i][j];
			if(i == 0 && j == 0){
				res[i][j] = cost;
			}else{
				int pc1 = (i>0)? res[i-1][j] : INT_MAX/2;
				int pc2 = (j>0)? res[i][j-1] : INT_MAX/2;
				res[i][j] = min(pc1 + cost, pc2 + cost);
			}
		}
	}
	// printf("%d\n", res[m-1][n-1]);
	return res[m-1][n-1];
}

int main(int argc, char **argv){
	vector<vector<int>> grid;
	grid.push_back({1,3,1});
	grid.push_back({1,5,1});
	grid.push_back({4,2,1});

	printf("%d\n", minPathSumBrute(grid));
	printf("%d\n", minPathSum(grid));

	const int NUMS = 100000;

	{
		double stime = microtime();
		for(int i=0; i<NUMS; i++){
			minPathSumBrute(grid);
		}
		double etime = microtime();
		printf("%.6f\n", etime - stime);
	}
	{
		double stime = microtime();
		for(int i=0; i<NUMS; i++){
			minPathSum(grid);
		}
		double etime = microtime();
		printf("%.6f\n", etime - stime);
	}

	return 0;
}

/*
64. Minimum Path Sum
[MEDIUM]

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
