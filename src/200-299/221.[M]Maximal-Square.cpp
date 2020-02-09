#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 扫描, 并修改输入数据.
* num[i][j] = min(left, up) + 1 if (left|up)

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

1 1 0 1 0 0
1 2 0 1 1 1
1 2 1 2 2 2
1 2 0 0 1 2

* 这算动态规划?
***********************************************************/
int maximalSquare(vector<vector<int>>& matrix) {
	int w = 0;
    int m = matrix.size();
	int n = matrix[0].size();
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(!matrix[i][j]) continue;
			int up = (i > 0)? matrix[i-1][j] : 0;
			int left = (j > 0)? matrix[i][j-1] : 0;
			matrix[i][j] = min(up, left) + 1;
			w = max(w, matrix[i][j]);
		}
	}
	return w * w; // 返回面积
}

/***********************************************************
# 解题思路

* 这道初看没有 Tricky 的地方, 就是找到 1 之后, 以 1 为出发点扫描找正方形.
* 先往右扫描, 找到最长的连续1的个数 w.
* 然后往下找第二行找 w. 如果 w < y1-y0+1, 即宽度小于高度, 停止扫描.
* 可优化的点应该是遍历过程跳过已找到的矩形.
	1. 用一个新的 matrix 来做标记, 存储要跳过的长度, 扫描时跳过.
	2. 存储方形的x到 map/hashmap 中, 扫描时判断是否遇到方形, 跳过.
	3. 修改原 matrix, 将找到的方形的最左边全置为宽度, 扫描时跳过.
* 优化方案2. 记得缓存淘汰, 避免占用过多. 另外单个1不缓存. 最多缓存 width/2 个矩形.
* 继续优化, 跳过后, 剩下的空间如果比已找到最大宽度/高度小, 停止.
* 时间复杂度: O(n)
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
