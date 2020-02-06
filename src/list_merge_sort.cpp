#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "./include/all.h"

using namespace std;

int cmp_cnt;
int visit_cnt;
int update_cnt;

void list_split(ListNode *head, ListNode **h1, ListNode **h2){
	ListNode *f, *s;
	s = head;
	f = head->next;
	while(f){
		f = f->next;
		visit_cnt ++;
		if(f){
			visit_cnt += 2;
			
			f = f->next;
			s = s->next;
		}
	}
	*h1 = head;
	*h2 = s->next;
	s->next = NULL; // split
	update_cnt ++;
}

ListNode* list_merge(ListNode *h1, ListNode *h2){
	// if(!h1) return h2;
	// if(!h2) return h1;
	ListNode dummy(-1);
	ListNode *flag = &dummy;
	while(1){
		cmp_cnt ++;
		visit_cnt ++;
		update_cnt ++;

		if(!h1){
			flag->next = h2;
			break;
		}
		if(!h2){
			flag->next = h1;
			break;
		}
		if(h1->val < h2->val){
			flag->next = h1;
			h1 = h1->next;
		}else{
			flag->next = h2;
			h2 = h2->next;
		}
		flag = flag->next;
	}
	return dummy.next;
}

ListNode* list_merge_sort(ListNode *head){
	visit_cnt ++;
	if(!head || !head->next) return head;
	ListNode *h1, *h2;
	list_split(head, &h1, &h2);
	h1 = list_merge_sort(h1);
	h2 = list_merge_sort(h2);
	return list_merge(h1, h2);
}

bool list_is_sorted(ListNode *head){
	while(head->next){
		if(head->val > head->next->val){
			return false;
		}
		head = head->next;
	}
	return true;
}

ListNode* helper2(ListNode *head, int maxlen, ListNode **next){
	visit_cnt ++;
	if(!head || !head->next){
		*next = NULL;
		return head;
	}
	
	ListNode *h1, *h2, *h3;
	
	h1 = head;
	h2 = head->next;
	h3 = head->next->next;
	h1->next = NULL;
	h2->next = NULL;
	visit_cnt += 3;
	update_cnt += 2;
	
	int len = 1;
	while(1){
		h1 = list_merge(h1, h2);
		len *= 2;
		if(maxlen == len){
			break;
		}
		if(!h3){
			break;
		}
		h2 = helper2(h3, len, &h3);
	}

	*next = h3;
	return h1;
}

ListNode* list_merge_sort2(ListNode *head){
	ListNode *n;
	return helper2(head, INT_MAX, &n);
}

int main(int argc, char **argv){
	ListNode *head = build_list("1->5->3->9->15->7->4->1->2");
	
	runtime();
	for(int i=1; i<10000; i++){
		srand(0);
		head = build_rand_list(i);
		cmp_cnt = visit_cnt = update_cnt = 0;
		head = list_merge_sort(head);
		printf("n: %3d   cmp: %5d vis: %5d upd: %5d\n",
			i, cmp_cnt, visit_cnt, update_cnt);

		head = build_rand_list(i);
		cmp_cnt = visit_cnt = update_cnt = 0;
		head = list_merge_sort2(head);
		printf("n: %3d   cmp: %5d vis: %5d upd: %5d\n",
			i, cmp_cnt, visit_cnt, update_cnt);

		if(!list_is_sorted(head)){
			printf("not sorted!\n");
			print_list(head);
		}
		printf("\n");
	}
	runtime();
	
	return 0;
}
