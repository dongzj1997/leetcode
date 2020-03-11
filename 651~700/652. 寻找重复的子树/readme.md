# 652. 寻找重复的子树

```c++
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4
因此，你需要以列表的形式返回上述重复子树的根结点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-duplicate-subtrees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

仅仅根据前序遍历的字符串可以唯一确定一个树吗？

乍一看不可以，要前序 +  中序才行。

但是如果我们使用 “#” 来表示 NULL，则是可以唯一确定的，

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string,int> mp;
        helper(root,result,mp);
        return result;
    }
    string helper(TreeNode*root,vector<TreeNode*>&result,
                  unordered_map<string,int>&mp)
    {
        string str;
        if(!root) return "#";
        str = to_string(root->val) + ' ' + helper(root->left,result,mp) + ' '+helper(root->right,result,mp);
        if(mp[str] == 1) result.push_back(root);
        mp[str]++;
        return str;
    }
};
```

---



