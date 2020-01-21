#include <stdio.h>
#include <string>
#include <vector>
#include "../include/util.h"

using namespace std;

int largestRectangleAreaBrute(vector<int>& heights) {
	int maxv = 0;
	for(int i=0; i<heights.size(); i++){
		for(int j=i; j<heights.size(); j++){
			int minh = INT_MAX;
			for(int n=i; n<=j; n++){
				minh = min(minh, heights[n]);
			}
			maxv = max(maxv, minh * (j-i+1));
		}
	}
	return maxv;
}

// FAILED, 变成几乎是 O(n^3), j 是否命中子集这个判断效率难提升
int largestRectangleArea1(vector<int>& heights) {
	// 虽然可以通过找有序子集来减少穷举, 但是, 怎么做呢?
	// 思路1: 直接思路, 把有序子集找出来, 单独存放, 遍历是的时候判断j是否命中有序子集, 有则快速跳过
	vector<vector<int>> sets;
	int s=0, e=0;
	int prev = -INT_MAX;
	for(int i=0; i<heights.size(); i++){
		if(heights[i] < prev || i == heights.size() - 1){
			if(i == heights.size() - 1){
				e = i;
			}else{
				e = i-1;
			}
			if(e > s){
				sets.push_back({s, e});
			}
			s = i;
		}
		prev = heights[i];
	}

	int maxv = 0;
	for(int i=0; i<heights.size(); i++){
		for(int j=i; j<heights.size(); j++){
			for(auto se : sets){
				if(se[0] <= j && j <= se[1]){
					j = se[1];
					break;
				}
			}

			int minh = INT_MAX;
			for(int n=i; n<=j; n++){
				minh = min(minh, heights[n]);
			}
			maxv = max(maxv, minh * (j-i+1));
		}
	}
	return maxv;
}

// 这道题的关键是逆向思维, 既然 j in set 这个操作比较慢, 那就找到 set 之后回溯 j
// 而且, 1个元素也当做子集统一处理
// * 如果没有使用逆向思维, 这道就永远不可能解出来!
int largestRectangleArea2(vector<int>& heights) {
	int maxv = 0;
	int s=0, e=0;
	int prev = -INT_MAX;
	for(int i=0; i<heights.size(); i++){
		if(heights[i] < prev || i == heights.size() - 1){
			if(i == heights.size() - 1){
				e = i;
			}else{
				e = i-1;
			}

			int minh = heights[e];
			for(int j=e; j>=0; j--){
				minh = min(minh, heights[j]);
				maxv = max(maxv, minh * (e-j+1));
			}

			s = i;
		}
		prev = heights[i];
	}
	return maxv;
}

int main(int argc, char **argv){
	vector<int> ds;
	ds = {2,1,5,6,2,3};
	printf("%d\n\n", largestRectangleAreaBrute(ds));
	printf("%d\n\n", largestRectangleArea2(ds));

	const int NUMS = 100000;
	ds = {2,1,5,6,2,3, 5, 6, 7, 2, 1, 8, 2,3,4};
	{
		double stime = microtime();
		for(int i=0; i<NUMS; i++){
			largestRectangleAreaBrute(ds);
		}
		double etime = microtime();
		printf("%.6f\n", etime - stime);
	}
	{
		double stime = microtime();
		for(int i=0; i<NUMS; i++){
			largestRectangleArea2(ds);
		}
		double etime = microtime();
		printf("%.6f\n", etime - stime);
	}

	return 0;
}

/*
问题简化为: 相邻的数字组成一个列表, 然后将列表内的数字全设置为与最小值相等, 求和 Sum. 相当于由n个最小的矩形组成一个新的矩形, 求面积. 找出这样的 Sum 或者面积的最大值.

初始的思路是全排列, 然后进行优化. 那么, 优化空间的空间在哪呢?

当数字是有序的(注意, *有序性*是解决很多问题的优化基础), 那么最小的数字只能与最大的数字组合才能得到最大的结果, 因为最小的数字与第二大组合得到的结果肯定要更小. 当有序子集外的某一元素 X 与这个有序子集 S 结合时, 直接与有序集合内的最大值组合.

所以, 解题的思路找到有序的局部集合, 然后不对子集进行穷举. 优化空间就在于此.

查找有序子集是 O(n) 操作, 比组合 O(n^2) 当然更好.


Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/