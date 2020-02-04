#include <stdio.h>
#include <math.h>
#include <list>
#include "util.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int tree_depth(TreeNode *n){
	if(!n){
		return 0;
	}
	return 1 + max(tree_depth(n->left), tree_depth(n->right));
}

TreeNode* bst_find(TreeNode *root, int val){
	if(!root) return NULL;
	if(val == root->val) return root;
	if(val < root->val){
		return bst_find(root->left, val);
	}else{
		return bst_find(root->right, val);
	}
}

TreeNode* tree_find(TreeNode *root, int val){
	if(!root) return NULL;
	if(val == root->val) return root;
	TreeNode *n;
	n = tree_find(root->left, val);
	if(n) return n;
	return tree_find(root->right, val);
}

vector<TreeNode*> tree_nodes_at_level(TreeNode *root, int l, bool withNull=false){
	vector<TreeNode*> ret;
	list<TreeNode*> q;
	q.push_back(root);
	while(!q.empty()){
		if((l--) == 0){
			ret.assign(q.begin(), q.end());
			return ret;
		}
		for(int i=q.size(); i>0; i--){
			TreeNode *n = q.front();
			q.pop_front();
			if(n){
				if(withNull || n->left) q.push_back(n->left);
				if(withNull || n->right) q.push_back(n->right);
			}else{
				if(withNull){
					q.push_back(NULL);
					q.push_back(NULL);
				}
			}
		}
	}
	return ret;
}

static TreeNode* build_tree(vector<int> ps){
	vector<TreeNode *> nodes;
	for(int i=0; i<ps.size(); i++){
		if(ps[i] != 0){
			TreeNode *n = new TreeNode(ps[i]);
			nodes.push_back(n);
			if(i > 0){
				int pid = (i-1)/2;
				TreeNode *p = nodes[pid];
				if(!p){
					printf("ERROR: NULL parent!\n");
					break;
				}
				if(i % 2 == 0){
					p->right = n;
				}else{
					p->left = n;
				}
			}
		}else{
			nodes.push_back(NULL);
		}
	}
	return nodes[0];
}

// 1,2,2,3,4,4,3
// static TreeNode* build_tree(string s){
// 	vector<string> ps = str_split(s, ",");
// 	vector<int> nums;
// 	for(auto p : ps){
// 		if(p.find("NULL") == string::npos && p.find("null") == string::npos){
// 			nums.push_back(atoi(p.c_str()));
// 		}else{
// 			nums.push_back(0);
// 		}
// 	}
// 	return build_tree(nums);
// }

//   01
//  /  \
// 02  03
// TODO: 采用二维画布的方式, 后序遍历, 画左子树, 画右子树, 然后画根节点.
// 1. 直接在画布上作图, 最后 print 画布.
// 2. 计算每一个块在画布上的坐标, 最后再 print.
void print_tree(TreeNode *root){
	int depth = tree_depth(root);
	int cell_width = 2;
	int max_level = depth - 1;
	for(int level=0; level<=max_level; level++){
		// int num = pow(2, level) * 2 - 1;
		int span = pow(2, max_level - level) * 2 - 1; // -1: 分隔符比跨越的元素个数少1
		int indent = pow(2, max_level - level - 1) * 2 - 1; // next_span
		
		printf("[");
		printf("%s", str_repeat(" ", indent*cell_width).c_str());
		vector<TreeNode*> nodes = tree_nodes_at_level(root, level, true);
		for(int j=0; j<nodes.size(); j++){
			if(j > 0){
				printf("%s", str_repeat(" ", span*cell_width).c_str());
			}
			TreeNode *node = nodes[j];
			if(node == NULL){
				printf("%*s", cell_width, " ");
			}else{
				printf("%0*d", cell_width, node->val);
			}
		}
		printf("%s", str_repeat(" ", indent*cell_width).c_str());
		printf("]\n");
		
		if(level < max_level){
			vector<TreeNode*> nodes2 = tree_nodes_at_level(root, level+1, true);
			int next_span = pow(2, max_level - level) - 1;
			int next_indent = pow(2, max_level - level - 1) - 1;
			
			int idn = indent - 1;
			int gap = 1;
			
			while(idn >= next_indent){
				int spn = span - (gap*2-1) - 1; // -1: '\'; -1: middle

				printf("[");
				printf("%s", str_repeat(" ", idn*cell_width).c_str());
				for(int j=0; j<nodes.size(); j++){
					if(j > 0){
						printf("%s", str_repeat(" ", spn*cell_width).c_str());
					}
					if(nodes[j] == NULL || nodes2[2*j] == NULL){
						printf("%*s", cell_width, " ");
					}else{
						printf("%*s", cell_width, "/");
					}
					printf("%s", str_repeat(" ", (gap*2-1)*cell_width).c_str());
					if(nodes[j] == NULL || nodes2[2*j+1] == NULL){
						printf("%*s", cell_width, " ");
					}else{
						printf("%-*s", cell_width, "\\");
					}
				}
				printf("%s", str_repeat(" ", idn*cell_width).c_str());
				printf("]\n");
				// idn -= (max_level - level + 1)/2;
				// gap += (max_level - level + 1)/2;
				idn -= 1;
				gap += 1;
				break;
			}
		}
	}
	printf("\n");
}
