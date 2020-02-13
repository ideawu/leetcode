#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 图遍历.
* 不使用标记板(用于标记已访问过的节点), 而是复用源数据.
* 在遍历之后, 恢复源数据.
***********************************************************/
bool helper(vector<vector<char>>& board, int i, int j, string word, int s){
	if(s == word.size()) return true;
	int m = board.size();
	int n = board[0].size();
	if(i < 0 || i >= m || j < 0 || j >= n) return false;
	if(board[i][j] != word[s]) return false;
	
	int c = board[i][j]; // 保存源数据, 遍历过后恢复.
	board[i][j] = '\0'; // 标记已访问过
	if(helper(board, i-1, j, word, s+1)) return true;
	if(helper(board, i+1, j, word, s+1)) return true;
	if(helper(board, i, j-1, word, s+1)) return true;
	if(helper(board, i, j+1, word, s+1)) return true;
	board[i][j] = c;
	
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	int m = board.size();
	int n = board[0].size();
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(helper(board, i, j, word, 0)) return true;
		}
	}
	return false;
}

int main(int argc, char **argv){
	vector<vector<char>> board;
	board = {
	  {'A','B','C','E'},
	  {'S','F','C','S'},
	  {'A','D','E','E'}
	};
	printf("%d\n", exist(board, "ABCCED"));
	board = {
	  {'A','B','C','E'},
	  {'S','F','C','S'},
	  {'A','D','E','E'}
	};
	printf("%d\n", exist(board, "SEE"));
	board = {
	  {'A','B','C','E'},
	  {'S','F','C','S'},
	  {'A','D','E','E'}
	};
	printf("%d\n", exist(board, "ABCB"));

	return 0;
}

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
