#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* num[r][c] = num[r-1][c-1] + num[r-1][c];
***********************************************************/
vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ret;
	ret.push_back({1});
	for(int i=1; i<numRows; i++){
		vector<int> row;
		for(int j=0; j<=i; j++){
			int a = j==0? 0 : ret[i-1][j-1];
			int b = j>=i? 0 : ret[i-1][j];
			row.push_back(a+b);
		}
		ret.push_back(row);
	}
	return ret;
}

int main(int argc, char **argv){
	print_matrix(generate(5));
	return 0;
}

/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
