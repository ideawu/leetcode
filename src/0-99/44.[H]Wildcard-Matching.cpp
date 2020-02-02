#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 递归穷举遍历, 时间复杂度主要受第 i 个 '*' 的影响, 需要尝试 n-i 次.
	n 是 s 长度. 最多出现 m/2 个 '*', m 是 p 的长度. 所以 O(n log n)
* 注意 special cases: s="", p="*" 或 p="**";
* 注意边界条件: '*' 要匹配到 end(), 即最后一个字符的后一位.
***********************************************************/
bool helper(string s, int si, string p, int pi){
	if(si == s.size() && pi == p.size()) return true;
	if(pi == p.size()) return false;
	if(si == s.size() && p[pi] != '*') return false; // s="", p="*" 或 p="**";
	
	if(p[pi] == '?' || p[pi] == s[si]){
		return helper(s, si+1, p, pi+1);
	}else if(p[pi] == '*'){
		// 连续的 * 优化
		do{
			pi++;
		}while(pi < p.size() && p[pi] == '*');
		// TODO: 还可以继续优化
		for(int i=si; i<=s.size(); i++){
			if(helper(s, i, p, pi)) return true;
		}
	}
	return false;
}
bool isMatch(string s, string p) {
    return helper(s, 0, p, 0);
}

int main(int argc, char **argv){
	printf("%d\n", isMatch("aa", "a"));
	printf("%d\n", isMatch("aa", "*"));
	printf("%d\n", isMatch("cb", "?a"));
	printf("%d\n", isMatch("adceb", "*a*b"));
	printf("%d\n", isMatch("acdcb", "a*c?b"));

	printf("\n");
	
	printf("%d\n", isMatch("", ""));
	printf("%d\n", isMatch("", "*"));
	printf("%d\n", isMatch("", "**"));
	printf("%d\n", isMatch("", "?"));
	printf("%d\n", isMatch("", "*?"));
	return 0;
}

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/
