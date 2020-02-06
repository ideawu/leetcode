#include <stdio.h>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

static ListNode* list_tail(ListNode *h){
	while(h->next){
		h = h->next;
	}
	return h;
}

static ListNode* list_next(ListNode *h, int n){
	for(int i=0; i<n; i++){
		if(!h){
			return NULL;
		}
		h = h->next;
	}
	return h;
}

// 1->2->3->3->4->4->5
static ListNode* build_list(const string &str){
	ListNode *head = NULL;
	ListNode *prev = NULL;
	int s = 0;
	int e;
	for(int i=0; i<=str.size(); i++){
		if(i == str.size() || (str[i] == '-' && str[i+1] == '>')){
			e = i - 1;

			char buf[32];
			memcpy(buf, str.data() + s, e - s + 1);
			buf[e - s + 1] = '\0';

			// parseInt
			int n = atoi(buf);

			ListNode *node = new ListNode(n);
			if(!head){
				head = node;
			}
			if(prev){
				prev->next = node;
			}
			prev = node;

			i += 1;
			s = i + 1;
		}
	}
	return head;
}

static void print_list(ListNode *head){
	while(head){
		printf("%d", head->val);
		if(head->next){
			printf("->");
		}
		head = head->next;
	}
	printf("\n");
}

ListNode* build_rand_list(int len, int maxnum=50){
	ListNode *ret = new ListNode(rand()%maxnum);
	ListNode *f = ret;
	for(int i=1; i<len; i++){
		f->next = new ListNode(rand()%maxnum);
		f = f->next;
	}
	return ret;
}
