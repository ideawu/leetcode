#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 简单想法是两趟相反方向遍历
	正向判断从[0]出现行驶需要的最大欠油量 borrow.
	反向遍历判断从任何一点出发, 行驶到末尾时的剩余油量 remain.
* 显然, remain >= borrow 才行.
***********************************************************/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int max_borrow = 0;
	int borrow = 0;
	for(int i=0; i<gas.size(); i++){
		int g = gas[i];
		int c = cost[i];
		borrow -= g - c;
		max_borrow = max(max_borrow, borrow);
	}
	int remain = 0;
	for(int i=gas.size()-1; i>=0; i--){
		int g = gas[i];
		int c = cost[i];
		remain += g - c;
		if(remain >= max_borrow){
			return i;
		}
	}
	return -1;
}

/***********************************************************
# 解题思路

* 一趟遍历的方案.
* 原理: 从头出发到末尾, 记录最终欠油量 borrow 和中间出现的最大欠油量
	max_borrow, 以及最终剩余油量 remain.
* 如果 remain 不小于 max_borrow, 说明可行.
* 但问题是, 从哪个出发并不知道...
* 从任何一个可出发点出发, 到某个点时耗光油, 那么从它中间其它可出发点出发,
	会更快的耗光油. 所以, 在它的行驶范围内的出发点都不是正确的出发点. 
* 又是逆向思维.
***********************************************************/
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
	int ret = -1;
	int max_borrow = 0;
	int borrow = 0;
	int remain = 0;
	for(int i=0; i<gas.size(); i++){
		int g = gas[i];
		int c = cost[i];
		borrow -= g - c;
		if(remain == 0 && g-c >= 0){
			ret = i;
		}
		remain += g - c;
		if(remain < 0){
			remain = 0;
		}
		max_borrow = max(max_borrow, borrow);
	}
	if(remain >= max_borrow){
		return ret;
	}else{
		return -1;
	}
}

int main(int argc, char **argv){
	vector<int> gas, cost;
	gas = {1,2,3,4,5};
	cost = {3,4,5,1,2};
	printf("%d\n", canCompleteCircuit(gas, cost));
	printf("%d\n", canCompleteCircuit2(gas, cost));
	gas = {2,3,4};
	cost = {3,4,3};
	printf("%d\n", canCompleteCircuit(gas, cost));
	printf("%d\n", canCompleteCircuit2(gas, cost));
	return 0;
}

/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

Note:

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.
Example 1:

Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: 
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
*/
