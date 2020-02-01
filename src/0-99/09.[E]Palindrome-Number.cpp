#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 当然, 转成字符串再对比这种方法比较直观, 不过, 直接按十进制移位组成一
	个新的整数然后对比: x/=10; n=n*10+x%10;
* 注意边界条件和特殊 case.
***********************************************************/
bool isPalindrome(int x) {
	return false;
}

int main(int argc, char **argv){
	printf("%d\n", isPalindrome(121));
	printf("%d\n", isPalindrome(-121));
	printf("%d\n", isPalindrome(10));
	printf("%d\n", isPalindrome(11));
	printf("%d\n", isPalindrome(1221));
	return 0;
}

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/
