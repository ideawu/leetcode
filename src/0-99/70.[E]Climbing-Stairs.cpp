#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

***********************************************************/
int climbStairs(int n) {
	if(n == 1){
		return 1;
	}
    int p[2] = {1, 2};
	for(int i=3; i<=n; i++){
		int c = p[0] + p[1];
		p[0] = p[1];
		p[1] = c;
	}
	return p[1];
}

int main(int argc, char **argv){
	printf("%d\n", climbStairs(2));
	printf("%d\n", climbStairs(3));
	printf("%d\n", climbStairs(4));
	return 0;
}

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
