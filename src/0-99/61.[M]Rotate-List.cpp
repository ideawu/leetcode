#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 引入辅助节点
* 使用前后指针 p, n, 尝试移动前指针 n, 如果间隔大于等于 k, 同时移动 p
* 记录链表长度 s, 如果 k 大于等于链表长度, 取模 m
* 	后指针 p 应该移动到移动第 s-m-1 位置
***********************************************************/
ListNode* rotateRight(ListNode* head, int k) {
	if(k == 0) return head;
	ListNode *p = head;
	ListNode *n = head;
	int s = 0;
	while(1){
		s ++;
		if(n->next == NULL){
			if(k >= s){
				int m = k % s;
				if(m == 0){
					break;
				}
				int idx = s - m - 1;
				// p at[0]
				while(--idx >= 0){
					p = p->next;
				}
			}
			ListNode *nh = p->next;
			n->next = head;
			p->next = NULL;
			return nh;
		}
		if(s > k){
			p = p->next;
		}
		n = n->next;
	}
	return head;
}

/***********************************************************
# 解题思路

* 将链表首尾相连, 同时得出长度 s, 然后 m=k%s, 断开头节点 s-m-1 个节点后面即可 
***********************************************************/
ListNode* rotateRight2(ListNode* head, int k) {
	int s = 1;
	ListNode *n = head;
	while(n->next){
		s ++;
		n = n->next;
	}
	n->next = head;
	
	int m = k % s;
	int i = s - m - 1;
	n = head;
	while(--i >= 0){
		n = n->next;
	}
	
	head = n->next;
	n->next = NULL;
	return head;
}

// 第3种, 翻转全表, 然后翻转 k 个节点, 然后再翻转剩下的全部节点.

int main(int argc, char **argv){
	ListNode *head = build_list("1->2->3->4->5");
	head = rotateRight2(head, 2);
	print_list(head);
	
	head = build_list("0->1->2");
	head = rotateRight2(head, 4);
	print_list(head);
	return 0;
}

/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/
