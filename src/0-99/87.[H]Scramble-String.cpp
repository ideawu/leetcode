#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

bool isScramble(string s1, string s2) {
	// printf("%s %s\n", s1.c_str(), s2.c_str());
	if(s1.size() == 1){
		return s1[0] == s2[0];
	}
	for(int i=0; i<s1.size()-1; i++){
		string a = s1.substr(0, i+1);
		string b = s1.substr(i+1);
		string c = s2.substr(0, a.size());
		string d = s2.substr(a.size());
		if(isScramble(a, c) && isScramble(b, d)){
			return true;
		}
		string e = s2.substr(0, b.size());
		string f = s2.substr(b.size());
		if(isScramble(b, e) && isScramble(a, f)){
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv){
	string s1 = "great", s2 = "rgeat";
	printf("%d\n", isScramble(s1, s2));

	{
		string s1 = "abcde", s2 = "caebd";
		printf("%d\n", isScramble(s1, s2));

	}
	return 0;
}


/*
87. Scramble String
[HARD]

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

	great
   /	\
  gr	eat
 / \	/  \
g   r  e   at
		   / \
		  a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

	rgeat
   /	\
  rg	eat
 / \	/  \
r   g  e   at
		   / \
		  a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

	rgtae
   /	\
  rg	tae
 / \	/  \
r   g  ta  e
	   / \
	  t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false
*/
