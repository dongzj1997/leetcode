# 23题 合并K个排序链表

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
https://leetcode-cn.com/problems/merge-k-sorted-lists/

输入:\
[\
  1->4->5,\
  1->3->4,\
  2->6\
]\
输出: 1->1->2->3->4->4->5->6

先定义N 是节点的总数目，k是链表数目

## 方法1 暴力排序法

算法的主要思想是遍历所有链表，将所有节点的值放到一个数组中，再将这个数组排序，然后遍历所有元素得到正确顺序的值，用遍历得到的值，创建一个新的有序链表。

算法的时间复杂的为O(N*logN)
空间复杂度为O(N)

评价：这个算法看似简单，但实际上算法的效率并不差，尤其是当k和N同等数量级时，但是算法的空间复杂度较高。

## 方法2 逐一比较

比较k个链表的节点头，选出最小的那个接在最终有序链表后面。

算法的时间复杂的为O(N*k)
空间复杂度为O(1)

**评价**：很显然，这个算法有重复比较的问题，所以算法的效率不高。

## 方法3 用优先队列优化方法 2

方法2最大的问题是重复比较，如果使用优先级比较队列可以进一步节省时间。

```python
from Queue import PriorityQueue

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head = point = ListNode(0)
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.val, l))
        while not q.empty():
            val, node = q.get()
            point.next = ListNode(val)
            point = point.next
            node = node.next
            if node:
                q.put((node.val, node))
        return head.next
```

**复杂度分析：** 由于每次插入节点的时间为logk，而查找队列中最小的一个元素的时间为O(1)，所以总的时间复杂度为O(N*logk)

空间复杂度为O(1)  （用于存储结果）

## 方法4 逐一两两合并链表

简单来讲，就是坐k-1 此两两合并链表

**复杂度分析：** 时间复杂度为O(N*k)

空间复杂度为O(1)  （用于存储结果）

## 方法4 分治法

这个方法沿用了上面的解法，但是进行了较大的优化。我们不需要对大部分节点重复遍历多次，因此，我们在每一次配对合并的过程中都会遍历几乎全部 N 个节点，并重复这一过程logk次。

```python
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if amount > 0 else lists

    def merge2Lists(self, l1, l2):
        head = point = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                point.next = l1
                l1 = l1.next
            else:
                point.next = l2
                l2 = l1
                l1 = point.next.next
            point = point.next
        if not l1:
            point.next=l2
        else:
            point.next=l1
        return head.next
```

**复杂度分析：** 

时间复杂度为O(N*logk)

空间复杂度为O(1)  
