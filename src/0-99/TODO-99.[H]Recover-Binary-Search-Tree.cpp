#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

int main(int argc, char **argv){
	return 0;
}

/***********************************************************
# 解题思路

* 直观的解法是按中序遍历生成一个数组, 找到1个错位的元素交换.
	根据大小关系决定前向搜索或者后向搜索, 找到另一个可正确交换的元素.
* 但题目要求用固定空间.
***********************************************************/
void recoverTree(TreeNode* root) {
    
}

/***********************************************************
# 解题思路

* 题目要求用固定空间(递归栈不算? 是 O(logN)).
* 那么还是按中序遍历, 遍历过程就能根据前一个访问的节点 p 和当前节点 n
	的大小判断当前节点是否错位.
* 然后, 怎么实现前向搜索和后向搜索?
	如果 n < p, 从 p 向上找 s, 如果 n>s 找右子树, 否则找根的左子树.
	如果 n > p, 从 p 向上找 s, 如果 n<s 找左子树, 否则找根的右了树.
***********************************************************/
void recoverTree(TreeNode* root) {
    
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
