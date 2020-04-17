# 783. 二叉搜索树结点最小距离

```c++
给定一个二叉搜索树的根结点 root，返回树中任意两节点的差的最小值。

 

示例：

输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树结点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \    
    1   3  

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
 

注意：

二叉树的大小范围在 2 到 100。
二叉树总是有效的，每个节点的值都是整数，且不重复。
本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

简单的中序遍历

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
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX, pre = 0;
        bool first = true;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        
        while(s.size()){
            auto t= s.top();
            s.pop();
            
            if(first) first = !first;
            else{
                ans = min(t->val - pre, ans);
            }
            pre = t->val;
            t = t->right;
            while(t){
                s.push(t);
                t = t->left;
            }
        }
        return ans;
    }
};
```

---



