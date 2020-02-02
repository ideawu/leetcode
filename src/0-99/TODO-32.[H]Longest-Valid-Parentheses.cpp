#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 1. 开始的思路是暴力破解, 从第0个字符开始找合法子串, 然后从第1个字符开始...
* 2. 遍历计数左括号lp和右括号rp, 如果rp>lp, 则lp和rp清空, 重新找.
	注意special case, 显然这种遍历是不严谨的. 那么如何改进呢?
***********************************************************/
int longestValidParentheses(string s) {
}

int main(int argc, char **argv){
	printf("%d\n", longestValidParentheses("())"));
	printf("%d\n", longestValidParentheses(")()())"));
	printf("%d\n", longestValidParentheses("(()())"));
	printf("%d\n", longestValidParentheses("())()())"));
	printf("%d\n", longestValidParentheses(")()()()()"));
	return 0;
}

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
