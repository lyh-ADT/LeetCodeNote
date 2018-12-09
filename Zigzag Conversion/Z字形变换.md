## [LeetCodeZ字形变换](https://leetcode-cn.com/problems/zigzag-conversion/submissions/)

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 `"LEETCODEISHIRING"` 行数为 3 时，排列如下：
```
L   C   I   R
E T O E S I I G
E   D   H   N
```
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：
```
string convert(string s, int numRows);
```
示例 1:
```
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
```
示例 2:
```
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
```

模拟法没试过,不知道会不会超时       
`result`中每个字符的下标(从0开始)是和`numRows`有关的,不明白的话可以用`matrix.cpp`输出一下矩阵试试
- 第一行和最后一行的副列是没有字母的
- 同一行中每一主列(垂直的一列)和相邻的副列(斜着的一列)相差`(numRows-行数)*2`
- 同一行中每一主列和相邻的主列相差`(numRows-1)*2`(就是第一行的主列间隔)     

所以可以得到
```
for (int r = 1; r <= numRows; ++r) {//题目要求按行的顺序
    i = r - 1;//每一行第一列的下标
    while (i < s.size()) {
        result += s[i];
        int gap = (numRows - r) * 2;//间隔

        if (1 < r && r < numRows && i + gap < s.size()) {
            /*
             * 1 < r  除掉第一行
             * r < numRows 除掉最后一行
             * i + gap < s.size() 下标不越界
             */
            result += s[i + gap];
        }
        i = i + (numRows - 1) * 2;//去到下一个主列
    }
}
```