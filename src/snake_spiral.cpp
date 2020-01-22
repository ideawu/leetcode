#include <iostream>
#include <vector>

using namespace std;

void print_spiral(int m , int n){
	vector<vector<int>> matrix(m);
	for(int i=0; i<m; i++){
		matrix[i] = vector<int>(n);
	}
	
	int num = 1;
	matrix[0][0] = num++;
	int i=0;
	int j=0;
	while(1){
		if(i == m-1 && j == n-1){
			break;
		}
	
		if(i == 0 || j == n-1){
			j++;
			if(j >= n){
				j --;
				i ++;
			}
			while(1){
				matrix[i][j] = num++;
				if(j == 0 || i == m-1){
					break;
				}
				i++;
				j--;
			}
		}else{
			i++;
			if(i >= m){
				i --;
				j ++;
			}
			while(1){
				matrix[i][j] = num++;
				if(i == 0 || j == n-1){
					break;
				}
				i--;
				j++;
			}
		}
	

	}
	
	for(auto r : matrix){
		for(auto c : r){
			printf("%2d ", c);
		}
		printf("\n");
	}
}

void print_spiral2(int m , int n){
	vector<vector<int>> matrix(m);
	for(int i=0; i<m; i++){
		matrix[i] = vector<int>(n);
	}
	
	int num = 1;
	matrix[0][0] = num++;
	int x0=0, y0=0; // 上右边缘上的点坐标
	int x1=0, y1=0; // 左下边缘上的点坐标
	int direction = 'd';
	while(1){
		if(x0 == m - 1 && y0 == n - 1){
			break;
		}

		y0 ++;
		if(y0 >= n){
			x0 ++;
			y0 = n - 1;
		}			
		x1 ++;
		if(x1 >= m){
			x1 = m - 1;
			y1 ++;
		}
		
		if(direction == 'd'){
			direction = 'u';
			for(int x=x0, y=y0; y>=y1; x++, y--){
				matrix[x][y] = num++;
			}
		}else{
			direction = 'd';
			for(int x=x1, y=y1; x>=x0; x--, y++){
				matrix[x][y] = num++;
			}
		}
	}
	
	for(auto r : matrix){
		for(auto c : r){
			printf("%2d ", c);
		}
		printf("\n");
	}
	printf("\n");
}

void print_spiral3(int m , int n){
	vector<vector<int>> matrix(m);
	for(int i=0; i<m; i++){
		matrix[i] = vector<int>(n);
	}
	
	int num = 1;
	int x = 0, y = 0; // 坐标
	int direction = 'u'; // 在初始之前是 up
	while(1){
		matrix[x][y] = num++;
		if(x == m - 1 && y == n - 1){
			break;
		}
		if(direction == 'u'){
			if(x == 0){
				direction = 'd';
				y ++;
				if(y >= n){
					x ++;
					y = n - 1;
				}
			}else if(y == n - 1){
				direction = 'd';
				x ++;
			}else{
				x --;
				y ++;
			}
		}else{
			if(y == 0){
				direction = 'u';
				x ++;
				if(x >= m){
					x = m - 1;
					y ++;
				}
			}else if(x == m - 1){
				direction = 'u';
				y ++;
			}else{
				x ++;
				y --;
			}
		}
	}
	for(auto r : matrix){
		for(auto c : r){
			printf("%2d ", c);
		}
		printf("\n");
	}
	printf("\n");
}

// To execute C++, please define "int main()"
int main() {
		print_spiral3(2, 3);
		print_spiral3(4, 1);
		print_spiral3(4, 6);
	return 0;
}


/* 
Your previous Plain Text content is preserved below:

Give you a matrix M * N where( 1 ≤	M ;	 1 ≤ N), the element in this matrix is from 1 to M*N.
Construct a new matrix which is spiral.

Input: 2,3
Outpuit: 
1 2 5
3 4 6

Input:
4 1

Output:
1
2
3
4
 */