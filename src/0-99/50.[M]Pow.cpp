#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这道题的优化点在于二分法.
***********************************************************/
double myPow(double x, int n) {
	if(n == 0) return 1;
	if(n == 1) return x;
	if(n < 0) return 1.0/myPow(x, -n);
	double r = myPow(x, n/2);
	r *= r;
	if(n % 2 == 1) r *= x;
	return r;
}

int main(int argc, char **argv){
	printf("%f\n", myPow(2, 10));
	printf("%f\n", myPow(2.1, 3));
	printf("%f\n", myPow(2, -2));
	return 0;
}

/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
