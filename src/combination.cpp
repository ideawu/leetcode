#include <algorithm>
#include <vector>

using namespace std;

int n1 = 0;
void c1(vector<vector<int>> &ret, vector<int> &nums, int s, vector<int> &pre){
	n1 ++;
	if(s == nums.size()){
		return;
	}
	pre.push_back(nums[s]);
	ret.push_back(pre);
	c1(ret, nums, s+1, pre);
	pre.pop_back();
	c1(ret, nums, s+1, pre);
}

int n2 = 0;
void c2(vector<vector<int>> &ret, vector<int> &nums, int s, vector<int> &pre){
	n2 ++;
	for(int i=s; i<nums.size(); i++){
		pre.push_back(nums[i]);
		ret.push_back(pre);
		c2(ret, nums, i+1, pre);
		pre.pop_back();
	}
}

void cu1(vector<vector<int>> &ret, vector<int> &nums, int s, vector<int> &pre){
	n1 ++;
	if(s == nums.size()){
		return;
	}
	int n = s + 1;
	while(n < nums.size() && nums[s] == nums[n]){
		n ++;
	}
	for(int i=s; i<n; i++){
		pre.push_back(nums[i]);
		ret.push_back(pre);
		cu1(ret, nums, n, pre);
	}
	for(int i=s; i<n; i++){
		pre.pop_back();
	}
	cu1(ret, nums, n, pre);
}

void cu2(vector<vector<int>> &ret, vector<int> &nums, int s, vector<int> &pre){
	n2 ++;
	for(int i=s; i<nums.size(); i++){
		if(i > s && nums[i] == nums[i-1]){
			continue;
		}
		pre.push_back(nums[i]);
		ret.push_back(pre);
		cu2(ret, nums, i+1, pre);
		pre.pop_back();
	}
}

int main(int argc, char **argv){
	vector<int> nums;
	
	nums.clear();
	for(int i=1; i<=4; i++){
		nums.push_back(i);
	}
	nums.insert(nums.begin()+2, nums[2]);
	std::sort(nums.begin(), nums.end());

	vector<vector<int>> ret;
	vector<int> pre;

	n1 = 0;
	ret.clear();
	pre.clear();
	cu1(ret, nums, 0, pre);
	printf("[%d %d]\n", n1, (int)ret.size());

	printf("\n");
	for(auto r : ret){
		for(auto n : r){
			printf("%d ", n);
		}
		printf("\n");
	}
	printf("\n");
	/*
	*/

	n2 = 0;
	ret.clear();
	pre.clear();
	cu2(ret, nums, 0, pre);
	printf("[%d %d]\n", n2, (int)ret.size());

	printf("\n");
	for(auto r : ret){
		for(auto n : r){
			printf("%d ", n);
		}
		printf("\n");
	}
	printf("\n");
	/*
	*/

	return 0;
}

