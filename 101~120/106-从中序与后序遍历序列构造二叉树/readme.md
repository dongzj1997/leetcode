# 106. 从中序与后序遍历序列构造二叉树

```c++
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return pre_order(0, inorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
    
    TreeNode *pre_order(int leftin, int rightin, int leftpost, int rightpost, vector<int> &in, vector<int> &post) {
        if (leftin > rightin) return NULL;
        TreeNode *root = new TreeNode(post[rightpost]);
        int rootin = leftin;
        while (rootin <= rightin && in[rootin] != post[rightpost]) rootin++;
        int left = rootin - leftin;
        root->left = pre_order(leftin, rootin - 1, leftpost, leftpost + left - 1, in, post);
        root->right = pre_order(rootin + 1, rightin, leftpost + left, rightpost - 1, in, post);
        return root;
    }
};
```

思路和上一题相同，只不过参数稍加改变，并且因为是后序遍历，所以根节点为最后一个数。
