#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

string build_line(vector<string>& words, int s, int e, int maxWidth){
	string ret;
	if(s == e || e == words.size() - 1){
		int len = 0;
		for(int i=s; i<=e; i++){
			if(i != s){
				len += 1;
				ret.push_back(' ');
			}
			len += words[i].size();
			ret.append(words[i]);
		}
		ret.append(maxWidth - len, ' ');
		return ret;
	}
	
	int len = 0;
	for(int i=s; i<=e; i++){
		len += words[i].size();
	}
	
	int n = e - s;
	int spaces = (maxWidth-len) / n;
	int remain = (maxWidth-len) % n;
	for(int i=s; i<=e; i++){
		ret.append(words[i]);
		if(i == e){
			break;
		}
		int ns = spaces;
		if(remain > 0){
			ns += 1;
			remain --;
		}
		ret.append(ns, ' ');
	}
	return ret;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;
	int s = 0;
	int e = s;
	int w = 0;
	while(e <= words.size()){
		if(e == words.size()){
			e -= 1;
			string str = build_line(words, s, e, maxWidth);
			ret.push_back(str);
			break;
		}
		
		w += (s == e)? 0 : 1;
		w += words[e].size();
		if(w < maxWidth){
			e += 1;
			continue;
		}
		if(w > maxWidth){
			w -= (s == e)? 0 : 1;
			w -= words[e].size();
			e -= 1;
		}
		
		string str = build_line(words, s, e, maxWidth);
		ret.push_back(str);
		
		s = e + 1;
		e = s;
		w = 0;
	}

	for(string str : ret){
		printf("[%s]\n", str.c_str());		
	}
	printf("\n");
	return ret;
}

int main(int argc, char **argv){
	vector<string> words;
	int maxWidth = 16;
	
	words = {"This", "is", "an", "example", "of", "text", "justification."};
	fullJustify(words, maxWidth);

	words = {"What","must","be","acknowledgment","shall","be"};
	fullJustify(words, maxWidth);
	
	words = {"Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"};
	maxWidth = 20;
 	fullJustify(words, maxWidth);
	
	return 0;
}
