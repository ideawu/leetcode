#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 分析: 生成一个包含 1-n 的数组, 以任意一个元素为根节点, 生成树.
	根节点左边是左子树, 右边是右子树.
* 不用实际生成数组, 用 [s,e] 表示即可.
***********************************************************/
vector<TreeNode*> helper(int s, int e){
	vector<TreeNode*> ret;
	if(s > e){
		ret.push_back(NULL);
	}else{
		for(int i=s; i<=e; i++){
			vector<TreeNode*> ls = helper(s, i-1);
			vector<TreeNode*> rs = helper(i+1, e);
			for(auto l : ls){
				for(auto r : rs){
					TreeNode *root = new TreeNode(i);
					// 复用内存
					root->left = l;
					root->right = r;
					ret.push_back(root);
				}
			}
		}
	}
	return ret;
}
vector<TreeNode*> generateTrees(int n) {
    return helper(1, n);
}


int main(int argc, char **argv){
	vector<TreeNode*> ts = generateTrees(4);
	for(auto t : ts){
		print_tree(t);
	}
	return 0;
}

/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
