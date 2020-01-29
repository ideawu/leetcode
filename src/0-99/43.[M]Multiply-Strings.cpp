#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

***********************************************************/
int helper(string &ret, string num, char ch, int shift){
	if(ch == '0'){
		return shift;
	}
	int a = ch - '0';
	int c = 0;
	for(int i=num.size()-1; i>=0; i--){
		int b = num[i] - '0';
		int s = ret[shift] - '0';
		int n = a * b + s + c;
		c = n / 10;
		n = n % 10;
		ret[shift] = n + '0';
		shift ++;
	}
	if(c != 0){
		ret[shift] = c + '0';
		shift ++;
	}
	return shift;
}

string multiply(string num1, string num2) {
    string ret(num1.size() + num2.size() + 1, '0');
	int s = 0;
	int n = 0;
	for(int j=num2.size()-1; j>=0; j--){
		n = helper(ret, num1, num2[j], s);
		s ++;
	}
	if(n == 0){
		n = 1;
	}
	ret.resize(n);
	std::reverse(ret.begin(), ret.end());
	return ret;
}

int main(int argc, char **argv){
	printf("%s\n", multiply("2", "3").c_str());
	printf("%s\n", multiply("123", "456").c_str());
	return 0;
}

/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
