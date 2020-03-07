# 572. 另一个树的子树   

```c++
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2
给定的树 t：

   4 
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subtree-of-another-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

周赛比这简单的一道题，同样的方法，为什么会超时呢？

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //if(s== NULL && t== NULL) return true;
        if(t== NULL) return true;
        if(s== NULL) return false;
        if(s->val == t->val) 
            return helper(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
        else
            return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    
    bool helper(TreeNode* s, TreeNode* t){
        if(s== NULL && t== NULL) return true;
        if(s== NULL || t== NULL) return false;
        return s->val == t->val && helper(s->left, t->left) && helper(s->right, t->right);
    }
};
```

---



