# 144. 二叉树的前序遍历

```c++
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

##  方法1:使用栈

```c++
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> s;

		auto t = root;
		while (t) { //先将最左边的入栈
			ans.push_back(t->val); //先序遍历
			s.push(t);
			t = t->left;
		}

		while (!s.empty()) { //当栈不为空时
			t = s.top();
			s.pop();
			t = t->right;

			while (t) {
				ans.push_back(t->val); //先序遍历
				s.push(t);
				t = t->left;
			}
		}
		return ans;
	}
};


```
另一种使用栈的实现方式 (巧妙利用后入先出的特点)：

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if not root:
            return res
        stack = [root]
        while stack: #非空
            node = stack.pop()
            res.append(node.val)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)
        return res

作者：powcai
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/di-gui-he-die-dai-by-powcai-5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

## 方法2：使用莫里斯遍历

主要思想是从根节点开始，对每个cur节点：


```c++
/*
若current没有左子节点
   a. 将current添加到输出
   b. 进入右子树，亦即, current = current.right
否则
   a. 在current的左子树中，令current成为最右侧节点的右子节点
   b. 进入左子树，亦即，current = current.left

      1
    /   \
   2     3
  / \   /
 4   5 6

首先，1 是根节点，所以将 current 初始化为 1。1 有左子节点 2，current 的左子树是

     2
    / \
   4   5

在此左子树中最右侧的节点是 5，于是将 current(1) 作为 5 的右子节点。令 current = cuurent.left (current = 2)。 现在二叉树的形状为:

     2
    / \
   4   5
        \
         1
          \
           3
          /
         6

对于 current(2)，其左子节点为4，我们可以继续上述过程

    4
     \
      2
       \
        5
         \
          1
           \
            3
           /
          6


由于 4 没有左子节点，添加 4 为输出，接着依次添加 2, 5, 1, 3 。节点 3 有左子节点 6，故重复以上过程。 最终的结果是 [4,2,5,1,6,3]。
*/

```

时间复杂度：每个前驱恰好访问两次，因此复杂度是 O(N)，其中 N 是顶点的个数，也就是树的大小。

对应的代码为：

```C++
class Solution { //莫里斯前序
public:
    TreeNode* getLeftMostRight(TreeNode* root) {
        auto node = root->left;
        while (node != NULL && node->right != NULL && node->right != root) {
            node = node->right;
        }
        return node;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root) {
            if (root->left == NULL) {
                res.push_back(root->val);
                root = root->right;
            } else {
                auto node = getLeftMostRight(root);
                if (node->right == root) {
                    node->right = NULL;
                    root = root->right;
                } else {
                    res.push_back(root->val);
                    node->right = root;
                    root = root->left;
                }
            }
        }
        return res;
    }
};
```

稍加修改，可以生成莫里斯中序


>我仔细研究了下该算法，总结Morris的算法核心就是左顾右盼
>左顾： 看左子树是否为空，若不为空，判断左子树的最右节点右指针是否指向自己
>右盼： 左边都处理了，就可以右移了
>
>前序遍历：左顾的时候发现其左子树为空或者其最右节点右指针没有指向自己，则收集该点的值
>中序遍历：左顾的时候发现其左子树为空或者其最右节点右指针有指向自己，则收集该点的值
>后序遍历：左顾的时候发现其左子树为空或者其最右节点右指针有指向自己，则逆序遍历其左子树的右边界节点



```C++
class Solution { //莫里斯中序
public:
    TreeNode* getLeftMostRight(TreeNode* root) {
        auto node = root->left;
        while (node != NULL && node->right != NULL && node->right != root) {
            node = node->right;
        }
        return node;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        while (root) {
            if (root->left == NULL) {
                res.push_back(root->val);
                root = root->right;
            } else {
                auto node = getLeftMostRight(root);
                if (node->right == root) {
                    node->right = NULL;
                    res.push_back(root->val);
                    root = root->right;
                } else {
                    node->right = root;
                    root = root->left;
                }
            }
        }
        return res;
    }
};

```



---

## 方法3：使用两次入栈的方式

```java

void preorderTraversalNew(TreeNode *root, vector<int> &path)
{
    stack< pair<TreeNode *, bool> > s;
    s.push(make_pair(root, false));
    bool visited;
    while(!s.empty())
    {
        root = s.top().first;
        visited = s.top().second;
        s.pop();
        if(root == NULL)
            continue;
        if(visited)
        {
            path.push_back(root->val);
        }
        else
        {
        //不同的遍历只需要改动这里的顺序就可以
            s.push(make_pair(root, true));
            s.push(make_pair(root->right, false));
            s.push(make_pair(root->left, false));
            
        }
    }
}

```
