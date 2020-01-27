#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 先将输入进行排序
* 将第一个元素加入到结果列表中
* 后面的元素如果与结果列表的最后元素有重叠, 合并进最后元素, 否则加入列表
***********************************************************/
bool cmp(vector<int> &a, vector<int> &b){
	return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), cmp);
	
	vector<vector<int>> ret;
	ret.push_back(intervals[0]);
	
	for(int i=1; i<intervals.size(); i++){
		vector<int> &p = ret.back();
		vector<int> r = intervals[i];
		if(r[1] < p[0] || r[0] > p[1]){
			ret.push_back(r);
		}else{
			p[0] = min(p[0], r[0]);
			p[1] = max(p[1], r[1]);
		}
	}
	
	return ret;
}

int main(int argc, char **argv){
	vector<vector<int>> its;
	
	its.clear();
	its.push_back({1,3});
	its.push_back({2,6});
	its.push_back({8,10});
	its.push_back({15,18});
	its = merge(its);
	print_matrix(its);
	
	printf("\n");

	its.clear();
	its.push_back({1,4});
	its.push_back({4,5});
	its = merge(its);
	print_matrix(its);
	
	return 0;
}

/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
