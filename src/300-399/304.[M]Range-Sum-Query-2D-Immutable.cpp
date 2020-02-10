#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这道题一是考察缓存设计, 然后是矩形(集合)运算:
	 union(并集), intersect(交集), except(差集).
* 增加 padding 以便让访问统一起来.
***********************************************************/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
		int n = matrix[0].size();
		cache.resize(m+1, vector<int>(n+1, 0));
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++){
				int un = cache[i][j-1] + cache[i-1][j] - cache[i-1][j-1];
				cache[i][j] = matrix[i-1][j-1] + un;
			}
		}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = cache[row2+1][col2+1];
		int un = cache[row1][col2+1] + cache[row2+1][col1] - cache[row1][col1];
		return total - un;
    }
private:
	vector<vector<int>> cache;
};

int main(int argc, char **argv){
	vector<vector<int>> matrix;
	matrix.push_back({3, 0, 1, 4, 2});
	matrix.push_back({5, 6, 3, 2, 1});
	matrix.push_back({1, 2, 0, 1, 5});
	matrix.push_back({4, 1, 0, 1, 7});
	matrix.push_back({1, 0, 3, 0, 5});

    NumMatrix* obj = new NumMatrix(matrix);
    printf("%d\n", obj->sumRegion(2, 1, 4, 3));
    printf("%d\n", obj->sumRegion(1, 1, 2, 2));
    printf("%d\n", obj->sumRegion(1, 2, 2, 4));
	return 0;
}

/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/
