#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 从队列各取出一个 range, 求交集.
* 然后留下 end 较大的一个, 从另一个队列取出下一个 range.
* 使用 STL 迭代器.
***********************************************************/
vector<int> intersect(vector<int> &r1, vector<int> &r2){
	vector<int> ret;
	if(r1[0] > r2[1] || r1[1] < r2[0]){
		//
	}else{
		ret = {max(r1[0], r2[0]), min(r1[1], r2[1])};
	}
	return ret;
}
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
	vector<vector<int>> ret;
    auto it1 = A.begin();
	auto it2 = B.begin();
	while(1){
		if(it1 == A.end() || it2 == B.end()){
			break;
		}
		auto &r1 = *it1;
		auto &r2 = *it2;
		auto inter = intersect(r1, r2);
		if(!inter.empty()){
			ret.push_back(inter);
		}
		if(r1[1] < r2[1]){
			it1 ++;
		}else{
			it2 ++;
		}
	}
	return ret;
}

int main(int argc, char **argv){
	vector<vector<int>> A, B;
	A = {{0,2},{5,10},{13,23},{24,25}};
	B = {{1,5},{8,12},{15,24},{25,26}};
	vector<vector<int>> ret = intervalIntersection(A, B);
	print_matrix(ret);
	return 0;
}

/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:



Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

*/
