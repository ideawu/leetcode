#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 用牛顿迭代法 x=(x+n/x)/2, 关键是停止条件.
***********************************************************/
int mySqrt(int n) {
	int x = n;
	int p = x;
	while(1){
		p = x;
		x = (x + n/x)/2;
		if(x >= p) break;
	}
	if(x > p) return x-1;
	else return x;
}

int main(int argc, char **argv){
	runtime();
	for(int i=1; i<1000000; i++){
		sqrt(i);
	}
	runtime();
	for(int i=1; i<1000000; i++){
		mySqrt(i);
	}
	runtime();
	// for(int i=1; i<INT_MAX; i++){
	// 	if(mySqrt(i) != (int)sqrt(i)){
	// 		printf("%d\n", i);
	// 		break;
	// 	}
	// }
	return 0;
}

/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/
