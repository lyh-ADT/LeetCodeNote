## [LeetCode合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/submissions/)

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:
```
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
```
***
一开始想到的是`Submit1.cpp`, 遍历数组, 每次在数组中每个元素指向的节点中找出最小的, 接到`tail`后面           
后来想到可以用之前做过的[合并两个有序链表](../Merge\ Two\ Sorted\ Lists/合并两个有序链表.md)来两两合并
不过两种的时间复杂度都是O(n<sup>2</sup>)