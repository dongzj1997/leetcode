# 116. 填充每个节点的下一个右侧节点指针

```c++
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

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

![img1](./116_sample.png)
```c++

输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

最开始我的想法是这样的，申请一个大小不超过树的最大高度的数组，每个元素存储该层的上一个元素，在**前序遍历**时根据层数建立链表。

这种方法思路简单，但是申请了额外的空间，不符合题意。

```c++
class Solution {
public:
	vector<Node*> tmp{};
	Node* connect(Node* root) {
		helper(root, 0);
		return root;
	}
	void helper(Node* root, int deep) {
		if (root == nullptr)
			return;
		if (tmp.size() <= deep) {
			tmp.push_back(root);
		}
		else {
			tmp[deep]->next = root;
			tmp[deep] = root;
		}
		helper(root->left, deep + 1);
		helper(root->right, deep + 1);
	}
};
```

---

另一种方法这样实现：

```c++
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL || root->left == NULL)
            return;
        root->left->next = root->right; //在递归之前就把自己左右节点中间的线连好
        if (root->next)//如果root还有兄弟，
            root->right->next = root->next->left;//则root把自己的右节点和兄弟的左节点连起来。
        connect(root->left);
        connect(root->right);
    }
};
```

主体任然是先序遍历，分为两步走，第一步是把自己的左右节点连起来，第二部是找自己的兄弟，让自己的右节点和兄弟的左节点联系起来。

迭代的方法：

```c++
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        TreeLinkNode* pre = root;
        TreeLinkNode* cur = NULL;
        while (pre->left)
        {
            cur = pre;
            while (cur)
            {
                cur->left->next = cur->right;
                if (cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
    }
};
```
