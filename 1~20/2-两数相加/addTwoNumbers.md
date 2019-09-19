这题相对比较简单，主要考察链表的操作
唯一需要注意的是手动删除第一个节点防止内存泄漏
```c++
L = head; 
head = head->next; 
delete L; 
return head; //防止内存泄漏
```
