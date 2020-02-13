# 25-K 个一组翻转链表

```c++
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

讲解见注释

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
	ListNode* reverseKGroup(ListNode* head, int k) {


        // 检查链表长度是否满足翻转
        int canProceed = 0;
        ListNode* check = head;
        while (canProceed < k && check != nullptr) {
            check = check->next;
            canProceed++;
        }


        // 满足条件，进行翻转
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* cur = head;

        int count = 0;
        if (canProceed == k) {
            while (count < k && cur != nullptr) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
                count++;
            }
            if (next != nullptr) {
                // head 为链表翻转后的尾节点,next为新段的第一个节点
                head->next = reverseKGroup(next, k);
            }
            // prev 为链表翻转后的头结点
            return prev;
        }
        else {

            // 不满住翻转条件，直接返回 head 即可
            return head;
        }
	}
};
```

---



