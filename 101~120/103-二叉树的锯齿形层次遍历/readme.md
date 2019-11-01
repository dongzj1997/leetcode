# 103. 二叉树的锯齿形层次遍历

```c++
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

list或者queue反转比较耗时，特别是queue自身并不支持反转（list在c++是双向链表，可以相当于有反转功能），用reverse我觉得可能是耗时的

两个stack各自保存一层数据，然后先进后出的特性加上左右节点先后入栈的顺序细节（具体谁先谁后可以看代码）即可恰好对应zigZag的Z字形访问顺序：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> r;
        if (!root) return r;
        stack<TreeNode *> d1, d2;
        d1.push(root);
        TreeNode *curr = nullptr;
        vector<int> tmp;
        while (true) {
            while (!d1.empty()) {
                curr = d1.top();
                d1.pop();
                tmp.push_back(curr->val);
                if (curr->left) d2.push(curr->left);
                if (curr->right) d2.push(curr->right);
            }
            if (!tmp.empty()) {
                r.push_back(tmp);
                tmp.clear();
            } else break;

            while (!d2.empty()) {
                curr = d2.top();
                d2.pop();
                tmp.push_back(curr->val);
                if (curr->right) d1.push(curr->right);
                if (curr->left) d1.push(curr->left);
            }
            if (!tmp.empty()) {
                r.push_back(tmp);
                tmp.clear();
            } else break;
        }
        return r;
    }
};
```

