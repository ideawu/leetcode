#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Range{
	int s;
	int e;
	Range() : s(0), e(0){}
	int len(){return e-s+1;}
};

struct Match{
    vector<int> _map;
	Range range;
	int count;
	Match(){
		_map.resize(128, 0);
		count = 0;
	}
	void add(char c){
		int f = _map[c]++;
		if(f == 0 && _map[c] > 0){
			count ++;
		}
	}
	void del(char c){
		int f = _map[c]--;
		if(f > 0 && _map[c] == 0){
			count --;
		}
	}
};

// assume ASCII
string minWindow(string s, string t) {
    vector<int> testmap(128, 0);
	for(auto &c : t){
		testmap[c] = 1;
	}

	Range range;
	range.e = INT_MAX/2;

	Match find;
	for(int i=0; i<s.size(); i++){
		char c = s[i];
		
		int oldf = find.count;
		if(testmap[c] > 0){
			find.add(c);
		}
		int newf = find.count;

		if(oldf == 0 && newf == 1){
			find.range.s = i;
		}else if(newf == 3){
			find.range.e = i;
			// pop front
			while(find.count == 3){
				if(find.range.len() < range.len()){
					range = find.range;
				}
				char c = s[find.range.s];
				if(testmap[c] > 0){
					find.del(c);
				}
				find.range.s ++;
			}
		}
	}

	printf("%d %d %s\n", range.s, range.e, s.substr(range.s, range.len()).c_str());

	if(range.e != INT_MAX/2){
		return s.substr(range.s, range.len());
	}
	return "";
}

int main(int argc, char **argv){
	string s = "ADOBECODEBANC";
	string t = "ABC";

	minWindow(s, t);
	printf("\n");

	return 0;
}

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/