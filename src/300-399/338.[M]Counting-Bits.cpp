#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

***********************************************************/
vector<int> countBits(int num) {
	if(num == 0) return {0};
	vector<int> ret = {0};
	int c = 0;
	while(1){
		int n = pow(2, c++);
		for(int i=0; i<n; i++){
			if(ret.size() == num + 1){
				return ret;
			}
			ret.push_back(ret[i] + 1);
		}
	}
}

// i & (i - 1) 清除最低位的 1 之后, 比当前值小(已计算过), 就可以回溯了.
vector<int> countBits2(int num) {
	vector<int> res(num + 1, 0);
	for (int i = 1; i <= num; ++i) {
		res[i] = res[i & (i - 1)] + 1;
	}
	return res;
}

int main(int argc, char **argv){
	vector<int> ret, ret2;
	ret = countBits(8);
	print_array(ret);
	// ret = countBits(5);
	// print_array(ret);
	for(int i=0; i<1000; i++){
		ret = countBits(i);
		ret2 = countBits2(i);
		if(ret != ret2){
			print_array(ret);
			print_array(ret2);
			break;
		}
	}
	return 0;
}

/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/
