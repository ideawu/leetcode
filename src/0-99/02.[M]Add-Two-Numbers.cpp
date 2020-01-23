#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 申请新变量指向两个链表
* 待定结果保存到 l1 上, 如果 l1 比 l2 短, 则将 l2 的节点转接到 l1 上
* 所以 l2 肯定先遍历完
* l2 遍历完之后, 就是将 l1 剩余的节点与 carry 相加并算出新 carry
* 最后可能需要创建新节点
***********************************************************/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *a = l1;
	ListNode *b = l2;
	int carry = 0;
	while(1){
		int sum = carry + a->val + b->val;
		carry = sum / 10;
		a->val = sum % 10;

		if(!a->next){
			a->next = b->next;
			b->next = NULL;
		}

		if(!b->next){
			while(carry != 0){
				if(!a->next){
					a->next = new ListNode(carry);
					break;
				}
				a = a->next;
				int sum = carry + a->val;
				carry = sum / 10;
				a->val = sum % 10;
			}
			break;
		}

		a = a->next;
		b = b->next;
	}
	return l1;
}

int main(int argc, char **argv){
	ListNode *a = build_list("2 -> 4 -> 5");
	ListNode *b = build_list("5 -> 6 -> 4");
	print_list(a);
	print_list(b);
	ListNode *c = addTwoNumbers(a, b);
	print_list(a);
	print_list(b);
	print_list(c);
	return 0;
}

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
