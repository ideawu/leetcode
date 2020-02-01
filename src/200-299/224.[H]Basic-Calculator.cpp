#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 1. 用逆波兰式, 建立完逆波兰式之后再计算.
* 2. 其实建立逆波兰式的过程, 用两个 stack/vector, 一个存操作符,
	一个存运算符(和括号). 在遇到 ) 或者连续两个操作符(+/-) 时归约.
***********************************************************/
struct Token{
	int type;
	int val;
	Token() : type(0), val(0){}
	void reset(){type=0; val=0;}
};

// stack 没有 clear() 方法! WTF!!!
vector<Token> vars, ops;
Token t;

void merge(){
	Token op = ops.back(); ops.pop_back();
	if(op.type == ')'){
		while(ops.back().type != '('){
			merge();
		}
		ops.pop_back(); // pop '('
		return;
	}else{
		Token v2 = vars.back(); vars.pop_back();
		Token v1 = vars.back(); vars.pop_back();
		if(op.type == '+'){
			v1.val += v2.val;
			vars.push_back(v1);
		}else if(op.type == '-'){
			v1.val -= v2.val;
			vars.push_back(v1);
		}
	}
}
void token_end(){
	if(t.type == 'n'){
		vars.push_back(t);
	}else if(t.type == '+' || t.type == '-'){
		if(ops.size() > 0){
			Token po = ops.back();
			if(po.type == '+' || po.type == '-'){
				merge();
			}
		}
		ops.push_back(t);
	}else if(t.type == '('){
		ops.push_back(t);
	}else if(t.type == ')'){
		ops.push_back(t);
		merge();
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
		}else if(ch == '(' || ch == ')' || ch == '+' || ch == '-'){
			token_end();
			t.type = ch;
			token_end();
		}else if(isdigit(ch)){
			t.type = 'n';
			t.val = t.val * 10 + (ch - '0');
		}
	}
	token_end();
	
	// finish
	if(!ops.empty()){
		merge();
	}
	
	return vars.empty()? -1 : vars.back().val;
}

int main(int argc, char **argv){
	printf("%d\n", calculate("1 + 1"));
	printf("%d\n", calculate(" 2-1 + 2 "));
	printf("%d\n", calculate("(1+(4+5+2)-3)+(6+8)"));
	return 0;
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
