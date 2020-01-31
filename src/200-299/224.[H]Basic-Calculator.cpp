#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

int main(int argc, char **argv){
	return 0;
}

/***********************************************************
# 解题思路

* 用逆波兰式, 不需要建立完逆波兰式之后再计算, 而是边建立边计算.
* 用两个 stack, 一个存操作符, 一个存运算符(和括号).
***********************************************************/
int calculate(string s) {
    
}

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
