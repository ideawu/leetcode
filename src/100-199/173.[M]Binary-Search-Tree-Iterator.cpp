#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 直观的思路是中序遍历将树展开到数组中, 但不符合 O(log2 n) 内存占用要求.
* 所以, 应该是用 list 辅助进行中序遍历.
* 考察点是基本编程逻辑, 怎么把原来一次运行的循环变成受限运行, 一次执行一步.
***********************************************************/
class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		q.push_back(root);
	}
    
    /** @return the next smallest number */
	int next() {
		TreeNode *n = q.front();
		q.pop_front();
		if(n->left) q.push_back(n->left);
		if(n->right) q.push_back(n->right);
		printf("%d\n", n->val);
		return n->val;
	}
    
    /** @return whether we have a next smallest number */
	bool hasNext() {
		printf("%s\n", (q.empty()? "false" : "true"));
		return !q.empty();
	}
private:
	list<TreeNode*> q;
};

int main(int argc, char **argv){
	TreeNode *root = build_tree({7,3,15,0,0,9,20});
	print_tree(root);
	BSTIterator iterator(root);
	iterator.next();    // return 3
	iterator.next();    // return 7
	iterator.hasNext(); // return true
	iterator.next();    // return 9
	iterator.hasNext(); // return true
	iterator.next();    // return 15
	iterator.hasNext(); // return true
	iterator.next();    // return 20
	iterator.hasNext(); // return false
	return 0;
}

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

 

Example:



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false
 

Note:

next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
*/
