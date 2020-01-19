#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	printf("input:\n");
	for(auto &row : matrix){
		for(auto &e : row){
			printf("%d ", e);
		}
		printf("\n");
	}

	int rows = matrix.size();
	int cols = matrix[0].size();
    int row = 0;
	int col = 0;
	bool prev_rf = false;
	bool prev_cf = false;

	for(; col <= cols || row <= rows; col++, row++){
		bool row_end = (row >= rows);
		bool col_end = (col >= cols);
		// mind cross edge
		int r = row_end? (rows - 1) : row;
		int c = col_end? (cols - 1) : col;
		
		bool rf = false;
		bool cf = false;
		
		// a. set cell to 0 according to previous cell(left or top)
		if(!row_end){
			if(matrix[r][c] == 0){
				rf = true;
			}
			// not including matrix[r][c]
			for(int i=0; i<c; i++){
				if(matrix[r][i] == 0){
					rf = true;
					for(int n=0; n<r; n++){
						matrix[n][i] = 0;
					}
				}
				if(r > 1 && matrix[r-1][i] == 0){
					matrix[r][i] = 0;
				}
			}
		}
		if(!col_end){
			if(matrix[r][c] == 0){
				cf = true;
			}
			// not including matrix[r][c]
			for(int i=0; i<r; i++){
				if(matrix[i][c] == 0){
					cf = true;
					for(int n=0; n<c; n++){
						matrix[i][n] = 0;
					}
				}
				if(c > 1 && matrix[i][c-1] == 0){
					matrix[i][c] = 0;
				}
			}
		}
		
		// b. set previous row or col to 0 if previously found 0
		if(prev_rf){
			for(int i=0; i<=c; i++){
				matrix[row-1][i] = 0;
			}
		}
		if(prev_cf){
			for(int i=0; i<=r; i++){
				matrix[i][col-1] = 0;
			}
		}
		prev_rf = rf;
		prev_cf = cf;
	}
	
	printf("output:\n");
	for(auto &row : matrix){
		for(auto &e : row){
			printf("%d ", e);
		}
		printf("\n");
	}
}

int main(int argc, char **argv){
	vector<vector<int>> matrix;
	
	printf("\n");
	matrix.clear();
	matrix.push_back({1,1,1});
	matrix.push_back({1,0,1});
	matrix.push_back({1,1,1});
	setZeroes(matrix);

	printf("\n");
	matrix.clear();
    matrix.push_back({0,1,2,0});
    matrix.push_back({3,4,5,2});
    matrix.push_back({1,3,1,5});
	setZeroes(matrix);

	printf("\n");
	matrix.clear();
    matrix.push_back({0,1,2,1});
    matrix.push_back({3,4,5,0});
    matrix.push_back({1,3,1,5});
	setZeroes(matrix);
	
	return 0;
}

// 采用逐步扩大搜索范围的方式, 先搜索 1x1, 然后 2x2, 3x3...(处理 m != n 的情况)
// 竖直方向查找, 水平方向查找, 分别标记是否找到, 设为变量 vf, hf.
// a. 竖直方向遍历某个节点时, 如果左边是 0, 置为 0
// a. 水平方向遍历某个节点时, 如果上边是 0, 置为 0
// b. 如果前一轮 vf[n-1] = true, 那么前一轮的竖直方向应该全置 0, 并向外延一步
// b. 如果前一轮 hf[n-1] = true, 那么前一轮的水平方向应该全置 0, 并向外延一步
// 边界条件是关键点:
// 		需要遍历到 matrix 之外, 才能确保最后一次步骤 b 能得到执行.
// 		注意步骤 a 不包括右下角的节点

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/