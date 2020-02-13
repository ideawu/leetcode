#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 见 224.Basic Calculator
***********************************************************/
struct Token{
	int type;
	int val;
	Token():type(0),val(0){}
	void reset(){type=0;val=0;}
};

vector<Token> vars, ops;
Token t;

void merge(){
	while(!ops.empty()){ // a+b*c
		Token op = ops.back(); ops.pop_back();
		Token v2 = vars.back(); vars.pop_back();
		Token v1 = vars.back(); vars.pop_back();
		if(op.type == '+'){
			v1.val += v2.val;
		}else if(op.type == '-'){
			v1.val -= v2.val;
		}else if(op.type == '*'){
			v1.val *= v2.val;
		}else if(op.type == '/'){
			v1.val /= v2.val;
		}
		vars.push_back(v1);
	}
}

void token_end(){
	if(t.type == 'n'){
		vars.push_back(t);
		if(ops.size() > 0){
			Token op = ops.back();
			if(op.type == '*' || op.type == '/'){
				merge();
			}			
		}
	}else if(t.type == '+' || t.type == '-'){
		if(ops.size() > 0){
			Token op = ops.back();
			if(op.type == '+' || op.type == '-'){
				merge();
			}			
		}
		ops.push_back(t);
	}else{
		ops.push_back(t);
	}
	t.reset();
}

int calculate(string s) {
	vars.clear();
	ops.clear();
	for(int i=0; i<s.size(); i++){
		char ch = s[i];
		if(isspace(ch)){
			continue;
		}else if(isdigit(ch)){
			t.type = 'n';
			t.val = t.val * 10 + (ch - '0');
		}else{
			token_end();
			t.type = ch;
			token_end();
		}
	}
	token_end();
	// 最后要计算一次
	merge();
	
	return vars.empty()? -1 : vars[0].val;
}

int main(int argc, char **argv){
	printf("%d\n", calculate("3+2*2"));
	printf("%d\n", calculate(" 3/2 "));
	printf("%d\n", calculate(" 3+5 / 2 "));
	return 0;
}

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
