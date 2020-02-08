#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 采用穷举法(演进动态规划)
* 依次选定每一个节点作为买点, 计算其后的节点作为卖点时的利润.
* 时间复杂度是 O(n^2)
***********************************************************/
int maxProfit(vector<int>& prices) {
    int p = 0;
	for(int i=0; i<prices.size(); i++){
		for(int j=i+1; j<prices.size(); j++){
			p = max(p, prices[j]-prices[i]);
		}
	}
	return p;
}

/***********************************************************
# 解题思路

* 只需要一趟遍历, 只要记住之前的最低点即可.
***********************************************************/
int maxProfit2(vector<int>& prices) {
	int ret = 0;
	int low = INT_MAX;
	for(auto n : prices){
		low = min(low, n);
		ret = max(ret, n - low);
	}
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {7,1,5,3,6,4};
	printf("%d\n", maxProfit(nums));
	printf("%d\n", maxProfit2(nums));
	nums = {7,6,4,3,1};
	printf("%d\n", maxProfit(nums));
	printf("%d\n", maxProfit2(nums));
	return 0;
}

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
