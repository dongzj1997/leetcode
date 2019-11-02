# 117. 填充每个节点的下一个右侧节点指针 II

```c++
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 
```
示例：

![img1](./117_sample.png)

```c++


输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++

class Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr)
			return root;

		Node* pre;
		if (root->left && root->right) {
			root->left->next = root->right; 
			pre = root->right;
		}
		else if (root->left) {
			pre = root->left;
		}
		else if (root->right) {
			pre = root->right;
		}
		else {
			return root;
		}


		Node* tmp=root->next;

		while (tmp) {
			if (tmp->left) {
				pre->next = tmp->left;
				break;
			}
			else if (tmp->right) {
				pre->next = tmp->right;
				break;
			}
			else {
				tmp = tmp->next;
			}
		}

		
		connect(root->right); //很关键！！！ 一定要先right，后left
        connect(root->left);

		return root;
	}
};
```

---

这个题的大体思路和前一题相同，上一题是完全二叉树，这一题是不完全树，根据有无左右节点分别判断即可。

但是需要注意的有两点：

1. 如果root->next没有左右节点，不代表这一层没人了，还需要看看root->next->next等等，以此类推。

2. 一定要确保 **root->right 下的节点的已完全连接**，因为 root.left 下的节点的连接需要 root.left.next 下的节点的信息，若 root.right 下的节点未完全连接（即先对 root.left 递归），则 root.left.next 下的信息链不完整，将
返回错误的信息。可能出现的错误情况如下图所示。此时，底层最左边节点将无法获得正确的 next 信息。，如下所示：

```c
        //                  o root
        //                 / \
        //     root.left  o —— o  root.right
        //               /    / \
        //              o —— o   o
        //             /        / \
        //            o        o   o
```

**所以一定要先connect(root->right);，然后connect(root->left);**

---

>还有另一种解法，非递归，也很巧妙,作者为windliang：  
>利用解法一的思想，我们利用 pre 指针，然后一个一个取节点，把它连起来。解法一为什么没有像解法二那样考虑当前节点为 null 呢？因为我们没有添加为 null 的节点，就是下边的代码的作用。  
>第二个问题，怎么得到每次的开头的节点呢？我们用一个dummy指针，当连接第一个节点的时候，就将dummy指针指向他。此外，之前用的pre指针，把它当成tail指针可能会更好理解。如下图所示：  
>![img2](./2.jpg)  
>cur 指针利用 next 不停的遍历当前层。  
>如果 cur 的孩子不为 null 就将它接到 tail 后边，然后更新tail。  
>当 cur 为 null 的时候，再利用 dummy 指针得到新的一层的开始节点。  
>dummy 指针在链表中经常用到，他只是为了处理头结点的情况，它并不属于当前链表。  
>代码就异常的简单了。

```java
Node connect(Node root) {
    Node cur = root;
    while (cur != null) {
        Node dummy = new Node();
        Node tail = dummy;
        //遍历 cur 的当前层
        while (cur != null) {
            if (cur.left != null) {
                tail.next = cur.left;
                tail = tail.next;
            }
            if (cur.right != null) {
                tail.next = cur.right;
                tail = tail.next;
            }
            cur = cur.next;
        }
        //更新 cur 到下一层
        cur = dummy.next;
    }
    return root;
}
```