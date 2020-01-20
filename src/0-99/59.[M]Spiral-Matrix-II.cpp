#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix2(int m, int n) {
	vector<vector<int>> matrix(m);
	for(int i=0; i<matrix.size(); i++){
		matrix[i] = vector<int>(n);
	}
	int x0 = 0;
	int x1 = m - 1;
	int y0 = 0;
	int y1 = n - 1;
	int i = 0;
	int j = 0;
	int num = 1;
	while(1){
		if(x0 >= x1 && y0 >= y1){
			break;
		}
		
		for(j=y0; j<y1; j++){
			matrix[i][j] = num++;
		}
		for(i=x0; i<x1; i++){
			matrix[i][j] = num++;
		}
		for(j=y1; j>y0; j--){
			matrix[i][j] = num++;
		}
		for(i=x1; i>x0; i--){
			matrix[i][j] = num++;
		}
		i++;

		x0 += 1;
		x1 -= 1;
		y0 += 1;
		y1 -= 1;
	}
	if(x0 == x1 && y0 == y1){
		matrix[x0][y0] = num++;
	}

	for(auto r : matrix){
		for(auto c : r){
			printf("%3d ", c);
		}
		printf("\n");
	}
		printf("\n");
	return matrix;
}

vector<vector<int>> generateMatrix(int n) {
	return generateMatrix2(n, n);
}

int main(int argc, char **argv){
	generateMatrix2(3, 3);
	generateMatrix2(4, 4);
	generateMatrix2(4, 3);
	generateMatrix2(4, 6);
	return 0;
}

/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
