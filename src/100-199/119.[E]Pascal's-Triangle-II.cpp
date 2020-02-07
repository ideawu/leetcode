#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* Pascal's triangle 指 [row][i] = [row-1][i-1] + [row-1][row].
* 预先生成 k+1 长度的数组.
* 更新数组前, 保存数组当前值. 注意生成最后一个值的边界条件.
***********************************************************/
vector<int> getRow(int rowIndex) {
    vector<int> ret(rowIndex+1);
	ret[0] = 1;
	for(int i=1; i<=rowIndex; i++){
		int pp = 0;
		for(int j=0; j<=i; j++){
			int p = j==i? 0 : ret[j];
			ret[j] = pp + p;
			pp = p;
		}
	}
	return ret;
}

int main(int argc, char **argv){
	for(int i=0; i<6; i++){
		print_array(getRow(i));
	}
	return 0;
}

/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/
