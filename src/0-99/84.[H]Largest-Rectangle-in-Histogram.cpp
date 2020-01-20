

/*
相邻的数字组成一个列表, 然后将列表内的数字全设置为与最小值相等, 求和 Sum. 相当于相信的矩形组成一个新的矩形, 求面积. 找出这样的 Sum 或者面积的最大值.

初始的思路是全排列, 然后进行优化. 那么, 优化空间的空间在哪呢?

当数字是有序的(注意, *有序性*是解决很多问题的优化基础), 那么最小的数字只能与最大的数字组合才能得到最大的结果, 因为最小的数字与第二大组合得到的结果肯定要更小. 这样的话, 有序集合内求解就不需要全排列了.

特别的, 如果有序列表与另一个非有序列表连接之后, 非有序列表内部也不需要再做全排列, 只需要与有序列表的最大值做组合即可.

所以, 解题的思路找到有序的集合, 然后只进行必要的排列而不是全排列. 优化空间就在于此.

查找有序子集是 O(n) 操作, 比全排列 O(n^2) 当然更好.



Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/