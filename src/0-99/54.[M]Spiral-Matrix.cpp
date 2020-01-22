#include <stdio.h>
#include <string>
#include <vector>
#include "../include/util.h"

using namespace std;

// 如果一次只移动一步, 判断条件可能会比较多.
// 此类问题应该一次移动尽可能多的步数, 用 while 循环来移动
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ret;
	int m = matrix.size();
	int n = matrix[0].size();
	int x0=0, y0=0;
	int x1=m-1, y1=n-1;
	int x=0, y=0;
	while(1){
	}

	for(auto n : ret){
		printf("%d ", n);
	}
	printf("\n\n");

	return ret;
}

int main(int argc, char **argv){
	vector<vector<int>> grid;
	grid.push_back({1,2,3});
	grid.push_back({4,5,6});
	grid.push_back({7,8,9});
	print_matrix(grid);
	printf("\n");

	spiralOrder(grid);

	{
		vector<vector<int>> grid;
		grid.push_back({1,2,3, 4});
		grid.push_back({5,6,7,8});
		grid.push_back({9,10,11,12});
		print_matrix(grid);
	printf("\n");

		spiralOrder(grid);
	}

	return 0;
}

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
