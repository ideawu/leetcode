void setZeroes(vector<vector<int>>& matrix) {
    
}

// 采用逐步扩大搜索范围的方式, 先搜索 1x1, 然后 2x2, 3x3...(处理 m != n 的情况)
// 竖直方向查找, 水平方向查找, 分别标记是否找到, 设为变量 vf, hf.
// 竖直方向遍历某个节点时, 如果左边是 0, 置为 0
// 水平方向遍历某个节点时, 如果上边是 0, 置为 0
// 如果前一轮 vf[n-1] = true, 那么前一轮的竖直方向应该全置 0, 并向外延一步
// 如果前一轮 hf[n-1] = true, 那么前一轮的水平方向应该全置 0, 并向外延一步

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/