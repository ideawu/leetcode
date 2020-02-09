#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 递归暴力破解.
***********************************************************/
bool isUgly(int num) {
	if(num <= 0) return false;
    if(num <= 5) return true;
	if(num % 2 == 0 && isUgly(num/2)) return true;
	if(num % 3 == 0 && isUgly(num/3)) return true;
	if(num % 5 == 0 && isUgly(num/5)) return true;
	return false;
}

bool isUgly2(int num) {
    if (num <= 0) return false;
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;
    return num == 1;
}

int main(int argc, char **argv){
	printf("%d\n", isUgly(6));
	printf("%d\n", isUgly(8));
	printf("%d\n", isUgly(14));
	return 0;
}

/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:

Input: 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2
Example 3:

Input: 14
Output: false 
Explanation: 14 is not ugly since it includes another prime factor 7.
Note:

1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range: [−231,  231 − 1].
*/
