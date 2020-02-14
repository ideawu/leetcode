#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这道题出发思路是遍历所有单词, 依次找.
* O(n) 一般不是最佳, 而且题目中 eat 先于 oath 找到, 所以应该是对输入排序了.
* 对输入排序之后, 可以在遍历 matrix 时决定选哪个单词进行查找.
* 用 set 来存储输入单词, 既可以排序, 也可以在找到之后删除.
* 用 do{}while(0) 惯用法, 可以简化代码结构.
* 真正做下来, 这道题 Hard 的点在于工程性会复杂一些.
***********************************************************/
bool helper(vector<vector<char>>& board, int i, int j, const string &word, int s){
	int m = board.size();
	int n = board[0].size();
	if(s == word.size()) return true;
	if(i < 0 || i >= m || j < 0 || j >= n) return false;
	char ch = board[i][j];
	if(ch == '\0') return false;
	if(ch != word[s]) return false;
	
	board[i][j] = '\0';
	do{
		if(helper(board, i-1, j, word, s+1)) break;
		if(helper(board, i+1, j, word, s+1)) break;
		if(helper(board, i, j-1, word, s+1)) break;
		if(helper(board, i, j+1, word, s+1)) break;
		
		board[i][j] = ch;
		return false;
	}while(0);
	board[i][j] = ch;
	return true;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	vector<string> ret;
	set<string> ws(words.begin(), words.end());
	int m = board.size();
	int n = board[0].size();
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(ws.empty()){
				return ret;
			}
			
			int size = ret.size();
			
			string c(1, board[i][j]);
			auto it = ws.lower_bound(c);
			while(it != ws.end()){ // 可能有多个相同前缀的单词
				const string &w = *it;
				if(w[0] != board[i][j]) break;;
				if(helper(board, i, j, w, 0)){
					ret.push_back(w);
				}
				it ++;
			}
			
			// 将已找到的单词清除
			while(size < ret.size()){
				ws.erase(ret[size]);
				size ++;
			}
		}
	}
	return ret;
}

int main(int argc, char **argv){
	vector<vector<char>> board;
	board = {
	  {'o','a','a','n'},
	  {'e','t','a','e'},
	  {'i','h','k','r'},
	  {'i','f','l','v'}
	};
	vector<string> words = {"oath","pea","eat","ea", "rain"};
	vector<string> ret = findWords(board, words);
	for(auto w : ret){
		printf("%s\n", w.c_str());
	}
	return 0;
}

/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
*/
