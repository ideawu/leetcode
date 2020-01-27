#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 题目虽然没明说, 但从 Output 看, 结果要求有序的.
***********************************************************/
vector<vector<int>> insert(vector<vector<int>>& rs, vector<int>& r) {
	vector<vector<int>> ret;
	bool added = false;
	for(int i=0; i<rs.size(); i++){
		vector<int> &p = rs[i];
		if(p[1] < r[0]){
			ret.push_back(p);
		}else if(r[0] <= p[1] && r[1] >= p[0]){
			r[0] = min(p[0], r[0]);
			r[1] = max(p[1], r[1]);
		}else{
			if(r[0] < p[0]){
				added = true;
				ret.push_back(r);
			}
			ret.push_back(p);
		}
	}
	if(!added){
		ret.push_back(r);
	}
	return ret;
}

int main(int argc, char **argv){
	vector<vector<int>> rs;
	vector<int> r;

	rs.clear();
	rs.push_back({1,3});
	rs.push_back({6,9});
	
	r = {2,5};
	rs = insert(rs, r);
	print_matrix(rs);
	
	printf("\n");

	rs.clear();
	rs.push_back({1,2});
	rs.push_back({3,5});
	rs.push_back({6,7});
	rs.push_back({8,10});
	rs.push_back({12,16});
	
	r = {4,8};
	rs = insert(rs, r);
	print_matrix(rs);
	
	
	return 0;
}

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
