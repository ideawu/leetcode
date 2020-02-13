#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 遍历整个表格, 如果遇到1, 将左右和下(左右)的1都置为-1, 结果计数加1.
***********************************************************/
void mark(vector<vector<int>>& grid, int i, int j){
	if(i==grid.size()) return;
	if(i==grid[0].size()) return;
	if(grid[i][j] != 1) return;
	grid[i][j] = -1;
	mark(grid, i, j+1);
	mark(grid, i, j-1);
	mark(grid, i+1, j);
}
int numIslands(vector<vector<int>>& grid) {
	int ret = 0;
	int m = grid.size();
	int n = grid[0].size();
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(grid[i][j] == 1){
				mark(grid, i, j);
				ret ++;
			}
		}
	}
	return ret;
}

int main(int argc, char **argv){
	vector<vector<int>> grid;
	
	grid.clear();
	grid.push_back({1,1,1,1,0});
	grid.push_back({1,1,0,1,0});
	grid.push_back({1,1,0,0,0});
	grid.push_back({0,0,0,0,0});
	printf("%d\n", numIslands(grid));
	print_matrix(grid);

	grid.clear();
	grid.push_back({1,1,0,0,0});
	grid.push_back({1,1,0,0,0});
	grid.push_back({0,0,1,0,0});
	grid.push_back({0,0,0,1,1});
	printf("%d\n", numIslands(grid));
	print_matrix(grid);
	
	return 0;
}

/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/
