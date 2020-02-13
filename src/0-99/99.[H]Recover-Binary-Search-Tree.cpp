#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 直观的解法是按中序遍历生成一个数组, 找到1个错位的元素交换.
	根据大小关系决定前向搜索或者后向搜索, 找到另一个可正确交换的元素.
***********************************************************/
void recoverTree(TreeNode* root) {
	list<TreeNode*> q;
	vector<TreeNode*> nodes;
	
	q.push_front(root);
	
	while(!q.empty()){
		TreeNode *n = q.front();
		while(n->left){
			q.push_front(n->left);
			n = n->left;
		}
		while(!q.empty()){
			n = q.front();
			q.pop_front();
			nodes.push_back(n);
			if(n->right){
				q.push_front(n->right);
				break;
			}
		}
	}
	
	for(int i=0; i<nodes.size()-1; i++){
		if(nodes[i]->val > nodes[i+1]->val){
			for(int j=i+1; j<nodes.size(); j++){
				if(j == nodes.size()-1 || nodes[i]->val < nodes[j+1]->val){
					std::swap(nodes[i]->val, nodes[j]->val);
					break;
				}
			}
			break;
		}
	}
}

/***********************************************************
# 解题思路

* 题目要求用固定空间(递归栈不算? 是 O(logN)).
* 那么还是按中序遍历, 遍历过程就能根据前一个访问的节点 p 和当前节点 n
	的大小判断当前节点是否错位.
* 找到错位节点后, 标记已找到, 继续遍历直到找到第一个比 p 大的节点或者最后一个节点.
***********************************************************/
bool helper(TreeNode *node, TreeNode **prev, TreeNode **found){
	if(!node){
		return false;
	}
	if(helper(node->left, prev, found)){
		return true;
	}
	if(*found){
		if((*found)->val < node->val){
			return true;
		}
	}else{
		if(node->val < (*prev)->val){
			*found = *prev;
		}
	}
	*prev = node;
	return helper(node->right, prev, found);
}
void recoverTree2(TreeNode* root) {
	TreeNode *prev = new TreeNode(INT_MIN);
	TreeNode *found=NULL;
	helper(root, &prev, &found);
	if(found){
		std::swap(prev->val, found->val);
	}
}

int main(int argc, char **argv){
	TreeNode *root;
	
	root = build_tree({1,3,0,0,2});
	print_tree(root);
	recoverTree2(root);
	print_tree(root);

	root = build_tree({3,1,4,0,0,2});
	print_tree(root);
	recoverTree2(root);
	print_tree(root);
	return 0;
}

/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/
