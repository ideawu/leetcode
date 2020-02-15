#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 用牛顿迭代法. x = (x + n/x)/2;
***********************************************************/
bool isPerfectSquare(int num) {
	int x = num;
	while(1){
		x = (x + num/x)/2;
		if(x * x == num) return true;
		if(x * x < num) return false;
	}
	return true;
}

int main(int argc, char **argv){
	printf("%d\n", isPerfectSquare(16));
	printf("%d\n", isPerfectSquare(14));
	return 0;
}

/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/
