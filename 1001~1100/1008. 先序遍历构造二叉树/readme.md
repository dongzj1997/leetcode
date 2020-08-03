# 1008. 先序遍历构造二叉树

```c++
返回与给定先序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。

(回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val。此外，先序遍历首先显示节点的值，然后遍历 node.left，接着遍历 node.right。）

 

示例：

输入：[8,5,1,7,10,12]
输出：[8,5,10,1,7,null,12]

 

提示：

1 <= preorder.length <= 100
先序 preorder 中的值是不同的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

利用中序遍历的特点分割数组。

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> vc;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vc = preorder;
        return hp(0, preorder.size()-1);
    }
    TreeNode* hp(int l, int r){
        if(l > r) return NULL;
        TreeNode* root = new TreeNode(vc[l]);
        int i = l + 1;
        while(i <= r){
            if(vc[i] > vc[l])
                break;
            i++;
        }
        root->left =  hp(l+1, i-1);
        root->right = hp(i, r);
        return root;
    }

    
};
```

---

