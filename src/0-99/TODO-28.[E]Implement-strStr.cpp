#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

int main(int argc, char **argv){
	return 0;
}

/***********************************************************
# 解题思路

***********************************************************/
int strStrBrute(string haystack, string needle) {
	int n = haystack.size() - needle.size();
	for(int i=0; i<=n; i++){
		for(int j=0; j<=needle.size(); j++){
			if(j == needle.size()){
				return i;
			}
			if(haystack[i+j] != needle[i+j]){
				break;
			}
		}
	}
	return -1;
}

/***********************************************************
# 解题思路

* TODO: KMP
***********************************************************/
int strStr(string haystack, string needle) {
}

/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
