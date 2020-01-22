#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

int main(int argc, char **argv){
	return 0;
}

/***********************************************************
# 解题思路

* O(n*logN) 复杂度的排序算法是堆排序, 和快速排序.
* 要求用常量空间, 显然不能用堆排序.
* 如果用快排, 递归栈不算占用空间吗? 好, 不算.
* 那就用快排, partition list 和 merge sorted list 已经做过
***********************************************************/
ListNode* sortList(ListNode* head) {
	
}

/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
