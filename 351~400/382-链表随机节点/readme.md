# 382-链表随机节点

```c++
给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。

进阶:
如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？

示例:

// 初始化一个单链表 [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom()方法应随机返回1,2,3中的一个，保证每个元素被返回的概率相等。
solution.getRandom();

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-random-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

### 解析

如果从总长度为n的序列中选取一个数作为随机数的话

可以先把第一个数设置为结果，然后设置一个指针i从2到n，每次以`1/i`的概率将结果替换为`nums[i]` 。

这样就能保证每个数选择到的概率都是`1/n` 。

### 进阶

如果要从长度为n的序列中选取k个数作为随机数的话，

先从 `n` 中选取前`k`个作为初始值，然后从`k+1`开始， 在`0~ i`之间生成一个随机数x，如果`x<k`，则用`nums[i]`替换掉`k`

如果要从

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i=2;
        ListNode* cur = head->next;
        int val = head->val;
        while(cur != nullptr) {
            if(rand() % i == 0) 
                val = cur->val; //第 i 节点以 1/i 概率替换当前值
            i++;
            cur = cur->next;
        }
        return val;
    }
    
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```

---



