## [LeetCode实现strStr()](https://leetcode-cn.com/problems/implement-strstr/)

实现 strStr() 函数。

给定一个`haystack`字符串和一个`needle`字符串，在`haystack`字符串中找出`needle`字符串出现的第一个位置 (从0开始)。如果不存在，则返回`-1`。

示例 1:
```
输入: haystack = "hello", needle = "ll"
输出: 2
```
示例 2:
```
输入: haystack = "aaaaa", needle = "bba"
输出: -1
```
说明:

当`needle`是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
***

用了最直接的暴力匹配, 果然拿不到第一    
看了第一名的

首先他判断`needle`的长度如果比`haystack`的长度长, 那么必然找不到匹配,返回`-1`          
直接将两个字符串相比较,
- 相等就`+=1`
- 不相等, `needle`回到开头, `haystack`回到`这次比较的下一个字符`
```
int i = 0;
int j = 0;
while(i<haystackLen && j<needleLen) {
    if (haystack[i] == needle[j]) {
        i++;
        j++;
    } else {
        i = i-j+1;
        j = 0;
    }
}
```
最后如果`needle`匹配完, 返回`haystack`的下标 - `needle`的下标
```
if (j == needleLen)
    return (i-j);
return -1;
```
他的时间复杂度和我的时间复杂度都是O(NM)`N = haystack.size(), M = needle.size()`, 但是我的时间上了`百位`, 他的只有`个位`, 也许是编译器或者处理器对他的写法有优化?