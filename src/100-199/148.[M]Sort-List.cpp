#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* O(n*logN) 复杂度的排序算法是堆排序, 和快速排序.
* 要求用常量空间, 显然不能用堆排序.
* 如果用快排, 递归栈不算占用空间吗? 好, 不算.
* 那就用快排, partition list 和 merge sorted list 已经做过
* partition: 让第1个元素比第2个元素小, 分别赋值给 lo, hi
	* 遍历 hi
	* 小于等于 lo 的接在 lo 前面, 大于 lo 的接在 hi 前面
***********************************************************/
int cmp_count1 = 0;
int swp_count1 = 0;
void partition_list(ListNode *head, ListNode **h1, ListNode **h2){
	ListNode *lo, *hi;
	lo = head;
	hi = head->next;

	cmp_count1++;
	// 让第一个元素比第二个元素小
	if(lo->val > hi->val){
		lo->next = hi->next;
		hi->next = lo;
		ListNode *tmp = lo;
		lo = hi;
		hi = tmp;
		swp_count1++;
	}

	lo->next = NULL; // 断开两个节点的连接
	
	int pivot = lo->val;

	ListNode *prev = hi;
	while(prev->next){
		ListNode *node = prev->next;
		cmp_count1 ++;
		if(node->val <= pivot){
			prev->next = node->next;
			node->next = lo;
			lo = node;
			swp_count1++;
		}else{
			prev = prev->next;
		}
	}

	*h1 = lo;
	*h2 = hi;
}

void sortListHelper(ListNode *head, ListNode **nh, ListNode **nt){
	if(!head->next){
		*nh = head;
		*nt = head;
		return;
	}
	ListNode *a, *b;
	partition_list(head, &a, &b);
	ListNode *h1, *t1, *h2, *t2;
	sortListHelper(a, &h1, &t1);
	sortListHelper(b, &h2, &t2);
	// merge
	t1->next = h2;

	*nh = h1;
	*nt = t2;
}

ListNode* sortList(ListNode* head) {
	ListNode *h, *t;
	sortListHelper(head, &h, &t);
	return h;
}

int cmp_count2 = 0;
int swp_count2 = 0;
// 选择排序
ListNode* sortList2(ListNode* head) {
	ListNode *dummy = new ListNode(0);
	dummy->next = head;

	ListNode *flag = dummy;
	while(flag->next){
		ListNode *prev = flag->next;
		int val = prev->val;
		while(prev->next){
			cmp_count2 ++;
			ListNode *node = prev->next;
			if(node->val < val){
				val = node->val;
				prev->next = node->next;
				node->next = flag->next;
				flag->next = node;
				swp_count2 ++;
			}else{
				prev = prev->next;
			}
		}
		flag = flag->next;
	}

	return dummy->next;
}

ListNode* random_list(int size){
	int val = rand() % 100;
	ListNode *head = new ListNode(val);
	ListNode *flag = head;
	for(int i=1; i<size; i++){
		int val = rand() % 10000;
		ListNode *n = new ListNode(val);
		flag->next = n;
		flag = flag->next;
	}
	return head;
}

bool is_sorted(ListNode *head){
	while(head->next){
		if(head->val > head->next->val){
			return false;
		}
		head = head->next;
	}
	return true;
}

int main(int argc, char **argv){
	ListNode *head;

	srand(time(NULL));
	srand(rand());

	const int NUMS = 10000;
	runtime();
	for(int i=max(1, NUMS-10); i<=NUMS; i++){
		cmp_count2 = 0;
		swp_count2 = 0;
		head = random_list(i);
		// print_list(head);
		head = sortList2(head);
		if(!is_sorted(head)){
			printf("FAILED\n");
		}
		// print_list(head);
		printf("%5d : cmp: %8d, swp: %6d\n", i, cmp_count2, swp_count2);
	}
	runtime();

	printf("##################\n");

	runtime();
	for(int i=max(1, NUMS-10); i<=NUMS; i++){
		cmp_count1 = 0;
		swp_count1 = 0;
		head = random_list(i);
		// print_list(head);
		head = sortList(head);
		if(!is_sorted(head)){
			printf("FAILED\n");
		}
		// print_list(head);
		printf("%5d : cmp: %8d, swp: %6d\n", i, cmp_count1, swp_count1);
	}
	runtime();

	return 0;
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
