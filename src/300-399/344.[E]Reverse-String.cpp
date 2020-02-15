#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

***********************************************************/
void reverseString(vector<char>& str) {
	int s = 0;
	int e = str.size() - 1;
	while(s < e){
		std::swap(str[s], str[e]);
		s ++;
		e --;
	}
}

int main(int argc, char **argv){
	vector<char> s;
	s = {'h','e','l','l','o'};
	reverseString(s);
	for(auto c : s){printf("%c ", c);} printf("\n");
	s = {'H','a','n','n','a','h'};
	for(auto c : s){printf("%c ", c);} printf("\n");
	return 0;
}

/*
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/
