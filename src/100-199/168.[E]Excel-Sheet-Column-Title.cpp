#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 26进制移位
* 关键点是从1开始计数, 而不是从0开始.
* 所以, 求余和清除最低位操作前, 要将操作数减1后再操作
***********************************************************/
string convertToTitle(int n) {
    string ret;
	do{
		n = n - 1;
		int c = n % 26;
		n = n / 26;
		ret.push_back(c + 'A');
	}while(n > 0);
	std::reverse(ret.begin(), ret.end());
	return ret;
}

int main(int argc, char **argv){
	for(int i=1; i<=26*3; i++){
		printf("%2d %s\n", i, convertToTitle(i).c_str());
	}
	return 0;
}

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
*/
