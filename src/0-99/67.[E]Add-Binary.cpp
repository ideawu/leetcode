#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 从右至左相加, 注意进位.
* 注意提前停止条件.
* 考察 string API 熟练度.
***********************************************************/
string addBinary(string a, string b) {
	int i = a.size()-1;
	int j = b.size()-1;
	int m = max(i,j);
	string ret(m+1, '0');
	int c = 0;
	while(i>=0 && j>=0){
		int n1 = (i>=0)? (a[i]-'0') : 0;
		int n2 = (j>=0)? (b[j]-'0') : 0;
		int n = n1 + n2 + c;
		c = n / 2;
		n = n % 2;
		ret[m--] = (n + '0');
		i --;
		j --;
	}
	if(c){
		ret.insert(0, 1, (char)(c+'0'));
	}
	return ret;
}

int main(int argc, char **argv){
	string a, b;
	a = "11";
	b = "1";
	printf("%s\n", addBinary(a,b).c_str());
	a = "1010";
	b = "1011";
	printf("%s\n", addBinary(a,b).c_str());
	return 0;
}

/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
