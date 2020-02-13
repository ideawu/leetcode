#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 文本解析一般用状态机.
* 用 en 来标记找到的词的结尾. 如果找到空白字符, 而且 s[en] 不是空白,
	则找到词. 否则 en = i-1.
* 从后往前遍历 string.
* 注意迭代器要迭代到 STL::rend(), 这时处理最后一个词.
* 注意空输入的情况.
***********************************************************/
string reverseWords(string s) {
	string ret;
	int en = s.size()-1;
	for(int i=s.size()-1; i>=-1; i--){
		if(i == -1 || isspace(s[i])){
			if(en >= 0 && !isspace(s[en])){
				if(!ret.empty()){
					ret.append(" ");
				}
				ret.append(s.substr(i+1, en-i));
			}
			en = i - 1;
		}
    }
	return ret;
}

int main(int argc, char **argv){
	printf("[%s]\n", reverseWords("the sky is blue").c_str());
	printf("[%s]\n", reverseWords("  hello world!  ").c_str());
	printf("[%s]\n", reverseWords("a good   example").c_str());
	return 0;
}

/*
Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
