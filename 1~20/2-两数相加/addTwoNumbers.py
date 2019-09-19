'''
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
'''

# for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        ans = ListNode(0)
        head = ans
        carry = 0
        t = None
        while l1 or l2:
            t1 = t2 = 0
            if l1:
                t1 = l1.val
                l1 = l1.next
            if l2:
                t2 = l2.val
                l2 = l2.next
            s = t1+t2 + carry
            t = ans
            ans.val = s % 10
            ans.next = ListNode(0)
            ans = ans.next
            carry = s//10
        if carry:
            ans.val = 1
        else:
            t.next = None
        return head

'''
另一种比较典型的写法
这种方法使用返回re.next的方式解决最后一个链表项可能是无用的0 的问题

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        re = ListNode(0)
        r=re
        carry=0
        while(l1 or l2):
            x= l1.val if l1 else 0
            y= l2.val if l2 else 0
            s=carry+x+y
            carry=s//10
            r.next=ListNode(s%10)
            r=r.next
            if(l1!=None):l1=l1.next
            if(l2!=None):l2=l2.next
        if(carry>0):
            r.next=ListNode(1)
        return re.next


'''