#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 一般这种题是指 ASCII 字符, 所以用数组做哈希表.
* 滑动窗口, 如果头部增加的字符有重复, 尝试减少尾部字符直到不重复.
***********************************************************/
int lengthOfLongestSubstring(string s) {
    vector<int> cs(128, 0);
	int len = 0;
	int ret = 0;
	for(int i=0; i<s.size(); i++){
		char ch = s[i];
		if((++cs[ch]) == 1){
			len ++;
			ret = max(ret, len);
		}else{ // repeated
			while(1){
				ch = s[i-len];
				if((--cs[ch]) == 1){ // del repeated
					break;
				}
				len --;
			}
		}
	}
	return ret;
}

// TODO: 优化, 哈希表不存计数, 而是存坐标.
int lengthOfLongestSubstring2(string s) {
	int i = 0;
	int ret = 0;
	for(int j=0; j<s.size(); j++){
	}
	return ret;
}

int main(int argc, char **argv){
	printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
	printf("%d\n", lengthOfLongestSubstring("bbbbb"));
	printf("%d\n", lengthOfLongestSubstring("pwwkew"));
	return 0;
}

/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
