#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 匹配的问题一般用 stack.
***********************************************************/
bool isValid(string s) {
    vector<char> vars;
	unordered_map<char,char> pairs = {
		{')', '('},
		{']', '['},
		{'}', '{'}
	};
	for(int i=0; i<s.size();i++){
		auto it = pairs.find(s[i]);
		if(it == pairs.end()){
			vars.push_back(s[i]);
		}else{
			char lp = it->second;
			if(vars.empty() || vars.back() != lp){
				return false;
			}
			vars.pop_back();
		}
	}
	return vars.empty();
}

int main(int argc, char **argv){
	printf("%d\n", isValid("()"));
	printf("%d\n", isValid("()[]{}"));
	printf("%d\n", isValid("(]"));
	printf("%d\n", isValid("([)]"));
	printf("%d\n", isValid("{[]}"));
	return 0;
}

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
