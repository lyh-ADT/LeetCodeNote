## [LeetCode删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/submissions/)

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：
```
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```
说明：
给定的 n 保证是有效的。

进阶：
你能尝试使用一趟扫描实现吗？
***
递归的话很简单, 所以直接就考虑进阶的算法

由于一次遍历,没办法知道当前是倒数第几个,所以用一个队列(queue)`temp`来保存节点的指针
删除的是倒数第`n`个节点, 那么只要找到倒数第`n+1`个就可以了
所以当队列里面有`n+2`个元素的时候,出队一个元素
```
queue<ListNode*> temp;
ListNode* nodeP = head;
while (nodeP != NULL) {
    temp.push(nodeP);
    if (temp.size() == n + 2) { temp.pop(); }
    nodeP = nodeP->next;
}
```
遍历完毕后有两种情况
- 队列中的第一个元素需要被删除`temp.size() == n`
这种情况也意味着`链表节点的个数 < n+1`,一次出队都没执行过,也就是说队列中的第一个元素就是链表的第一个元素,删除后应该返回下一个节点的指针,如果链表只有一个节点,删除后返回`NULL`
```
delete[] temp.front();
temp.pop();
if (temp.empty()) {
    return NULL;
} else {
    return temp.front();
}
```
- 队列中的第二个元素需要被删除`else`
用指针保存队列的第一个指针(指向倒数第`n+1`个节点的指针),删除下一个,如果有第三个,将第一个的`next`指向它
```
ListNode* front = temp.front();
temp.pop();
delete[] temp.front();
temp.pop();
if(temp.empty()){
    front->next = NULL;
}
else{
    front->next = temp.front();
}
return head;
```
***
通过后,看了看第一名的代码,发现了一个很奇怪的东西,写在程序的开头
```
static const auto io_sync_off=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
```
上网查了查, 是C++11的Lambda函数
```
// Lambda函数可以引用在它之外声明的变量, 这些变量的集合叫做一个闭包
// capture定义该函数使用闭包的方式
// "->返回类型"可以省略
[capture](参数列表)->返回类型{
    函数体
}
```
在声明后直接加`()`会直接调用, 感觉和JavaScript的函数差不多        
至于这个函数的作用
```
std::ios::sync_with_stdio(false);
```
关闭和`stdio`的同步, C和C++用的不是同一个输入输出流, 为了防止混用时不出错, 默认是开启的, 但是会导致不混用时多余的开销, 说简单点就是浪费时间
```
std::cin.tie(nullptr);
```
默认的情况下cin绑定的是cout，每次执行`<<`操作符的时候都要调用flush，这样会增加IO负担。可以通过tie(nullptr)（NULL）来解除cin与cout的绑定

总而言之,就是节省I/O时间,给自己的代码加上之后,用时少了一半!!!