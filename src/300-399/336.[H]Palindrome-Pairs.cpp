#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 用穷举.
* 考察点可能是怎么不拼接字符串而判断两个字符串在拼接后是回文.
* 可以用两个指针同时遍历两个字符串, 一个从 s1 头, 一个从 s2 尾.
	任何一个指针遍历完一个字符串后转到另一个.
* 注意结束条件, 空字符串.
* 遍历指针初始在开始之前(begin-1)和结束之后(end).
* 没发现 Tricky 的地方. 
***********************************************************/
bool isPalindrome(const string &a, const string &b){
	const string *p1 = &a;
	int i1 = -1;
	const string *p2 = &b;
	int i2 = p2->size();
	while(1){
		if(i2 == 0){
			p2 = &a;
			i2 = p2->size();
		}
		i2 --;
		if(p1 == p2 && i1 >= i2){
			return true;
		}
		
		if(i1 == p1->size()-1){
			p1 = &b;
			i1 = -1;
		}
		i1 ++;
		if(p1 == p2 && i1 >= i2){
			return true;
		}
		
		if(p1->at(i1) != p2->at(i2)){
			return false;
		}
	}
}
vector<vector<int>> palindromePairs(vector<string>& words) {
	vector<vector<int>> ret;
    for(int i=0; i<words.size()-1; i++){
    	for(int j=i+1; j<words.size(); j++){
    		string &a = words[i];
			string &b = words[j];
			if(isPalindrome(a, b)){
				ret.push_back({i, j});
			}
			if(isPalindrome(b, a)){
				ret.push_back({j, i});
			}
    	}
    }
	return ret;
}

int main(int argc, char **argv){
	vector<string> words = {"abcd","dcba","lls","s","sssll"};
	vector<vector<int>> ret = palindromePairs(words);
	print_matrix(ret);
	return 0;
}

/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:

Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]] 
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
Example 2:

Input: ["bat","tab","cat"]
Output: [[0,1],[1,0]] 
Explanation: The palindromes are ["battab","tabbat"]
*/
