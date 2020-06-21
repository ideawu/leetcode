#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路
* 用数组建立哈希表, 然后计数.
***********************************************************/
int numJewelsInStones(string J, string S) {
    vector<int> cache(256, 0);
    int ret = 0;
    
    for(char c : J){
        int d = (unsigned char)c;
        cache[d] = 1;
    }
    
    for(char c : S){
        int d = (unsigned char)c;
        if(cache[d]){
            ret ++;
        }
    }
    
    return ret;
}

int main(int argc, char **argv){
    printf("%d\n", numJewelsInStones("aA", "aAAbbbb"));
    printf("%d\n", numJewelsInStones("z", "ZZ"));
	return 0;
}

/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/
