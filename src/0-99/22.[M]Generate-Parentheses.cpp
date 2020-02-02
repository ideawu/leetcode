#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 符合二分渐进式组合穷举法, 该方法分别尝试访问左节点或者右节点, 并传递前序路径.
* 穷举过程要保持匹配, 所以 rp > lp 时才访问右节点.
* 如果已经访问到最后一个右节点了, 则将路径加到结果列表中.
***********************************************************/
void helper(vector<string> &ret, int lp, int rp, string &pre){
	if(rp == 0){
		ret.push_back(pre);
		return;
	}
	if(lp > 0){
		pre.push_back('(');
		helper(ret, lp-1, rp, pre);
		pre.pop_back();
	}
	if(rp > lp){
		pre.push_back(')');
		helper(ret, lp, rp-1, pre);
		pre.pop_back();
	}
}
vector<string> generateParenthesis(int n) {
    vector<string> ret;
	string pre;
	helper(ret, n, n, pre);
	return ret;
}

int main(int argc, char **argv){
	vector<string> ret;
	ret = generateParenthesis(3);
	for(auto s : ret){
		printf("%s\n", s.c_str());
	}
	printf("\n");
	return 0;
}
