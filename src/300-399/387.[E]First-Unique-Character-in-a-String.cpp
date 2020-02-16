#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 用哈希下标, 如有重复, 存-2, 然后遍历一遍哈希表, 找最小非负数下标.
***********************************************************/
int firstUniqChar(string s) {
	vector<int> count(26, -1);
	for(int i=0; i<s.size(); i++){
		int ch = s[i];
		int idx = ch - 'a';
		if(count[idx] == -1){
			count[idx] = i;
		}else if(count[idx] >= 0){
			count[idx] = -2;
		}
	}
	int ret = INT_MAX;
	for(int i=0; i<count.size(); i++){
		if(count[i] >= 0){
			ret = min(ret, count[i]);
		}
	}
	return ret == INT_MAX? -1 : ret;
}

int main(int argc, char **argv){
	printf("%d\n", firstUniqChar("leetcode"));
	printf("%d\n", firstUniqChar("loveleetcode"));
	return 0;
}

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
