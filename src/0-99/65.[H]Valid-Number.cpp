#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* sign(1) + dec(1) + dot + dec(2) + exp + sign(2) + dec(3)
***********************************************************/
bool isNumber(string s) {
	int sign = 0;
	int dec = 0;
	int status = 'star';
	for(int i=0; i<=s.size(); i++){
		char ch = (i<s.size())? s[i] : ' ';
		if(status == 'star'){
			// sign(1) + dec(1) + dot + dec(2) + exp + sign(2) + dec(3)
			if(isspace(ch)){
				//
			}else if(ch == '-' || ch == '+'){
				status = 'sign';
				sign = 1;
			}else if(isdigit(ch)){
				status = 'dec';
				dec = 1;
			}else if(ch == '.'){
				status = 'dot';
			}else{
				return false;
			}
		}else if(status == 'end'){
			if(isspace(ch)){
				//
			}else{
				return false;
			}
		}else if(status == 'sign'){
			// sign(1) + dec(1) + dot + dec(2) + exp + sign(2) + dec(3)
			if(ch == '.'){
				if(sign == 2){
					return false;
				}
				status = 'dot';
			}else if(isdigit(ch)){
				status = 'dec';
				if(sign == 1){
					dec = 1;
				}else if(sign == 2){
					dec = 3;
				}
			}else{
				return false;
			}
		}else if(status == 'dot'){
			// sign(1) + dec(1) + dot + dec(2) + exp + sign(2) + dec(3)
			if(isspace(ch)){
				if(dec == 1){
					status = 'end';
				}else{
					return false;
				}
				continue;
			}
			if(isdigit(ch)){
				status = 'dec';
				dec = 2;
			}else if(ch == 'e'){
				if(dec == 1){
					status = 'exp';
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else if(status == 'dec'){
			// sign(1) + dec(1) + dot + dec(2) + exp + sign(2) + dec(3)
			if(isspace(ch)){
				status = 'end';
				continue;
			}
			if(isdigit(ch)){
				//
			}else if(ch == '.'){
				if(dec == 1){
					status = 'dot';
				}else{
					return false;
				}
			}else if(ch == 'e'){
				if(dec == 1 || dec == 2){
					status = 'exp';
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else if(status == 'exp'){
			// sign(1) + dec(1) + dot + dec(2) + exp + sign(2) + dec(3)
			if(isdigit(ch)){
				status = 'dec';
				dec = 3;
			}else if(ch == '-' || ch == '+'){
				status = 'sign';
				sign = 2;
			}else{
				return false;
			}
		}
	}
	return status == 'end';
}

int main(int argc, char **argv){
	printf("%d\n", isNumber("0")); // true
	printf("%d\n", isNumber(" 0.1 ")); // true
	printf("%d\n", isNumber("abc")); // false
	printf("%d\n", isNumber("1 a")); // false
	printf("%d\n", isNumber("2e10")); // true
	printf("%d\n", isNumber(" -90e3   ")); // true
	printf("%d\n", isNumber(" 1e")); // false
	printf("%d\n", isNumber("e3")); // false
	printf("%d\n", isNumber(" 6e-1")); // true
	printf("%d\n", isNumber(" 99e2.5 ")); // false
	printf("%d\n", isNumber("53.5e93")); // true
	printf("%d\n", isNumber(" --6 ")); // false
	printf("%d\n", isNumber("-+3")); // false
	printf("%d\n", isNumber("95a54e53")); // false
	return 0;
}

/*
Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.
*/
