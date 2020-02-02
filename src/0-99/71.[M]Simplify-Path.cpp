#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 将字符串以 '/' 分隔, 遍历每一个名字, 如果是 '.' 则忽略, 如果是 '..'
* 则弹出 stack 一个元素. 
***********************************************************/
string simplifyPath(string path) {
    int s = 0;
	int e = 0;
	vector<string> ps;
	for(int i=0; i<=path.size(); i++){
		if(i == path.size() || path[i] == '/'){
			e = i - 1;
			if(s <= e){
				string dir = path.substr(s, e-s+1);
				if(dir == "."){
					//
				}else if(dir == ".."){
					if(!ps.empty()){
						ps.pop_back();
					}
				}else{
					ps.push_back(dir);
				}
			}
			s = i + 1;
		}
	}
	if(ps.empty()){
		return "/";
	}
	string ret;
	for(auto d : ps){
		ret.push_back('/');
		ret.append(d);
	}
	return ret;
}

int main(int argc, char **argv){
	printf("%s\n", simplifyPath("/home/").c_str());
	printf("%s\n", simplifyPath("/../").c_str());
	printf("%s\n", simplifyPath("/home//foo/").c_str());
	printf("%s\n", simplifyPath("/a/./b/../../c/").c_str());
	printf("%s\n", simplifyPath("/a/../../b/../c//.//").c_str());
	printf("%s\n", simplifyPath("/a//b////c/d//././/..").c_str());
	return 0;
}

/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
*/
