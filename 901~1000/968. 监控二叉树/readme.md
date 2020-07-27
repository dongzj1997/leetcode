# 968. 监控二叉树

```c++
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。

 

示例 1：



输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。
示例 2：



输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。

提示：

给定树的节点数的范围是 [1, 1000]。
每个节点的值都是 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-cameras
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

理清三种状态，分别判断即可

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
    int ans = 0;
    int minCameraCover(TreeNode* root) {
        int t = helper(root);
        if(t == 1)
            return ans + 1;
        return ans; 
    }
    int helper(TreeNode* root){
        if(root == nullptr) return 0; // 节点为空或者已经被监控
        if(root->left == nullptr && root->right == nullptr) return 1; // 告诉父节点，有被监控的需求,但是可以由父节点来监控
        int a = helper(root->left);
        int b = helper(root->right);
        if(a==1 || b==1) { //如果任意一个子节点有被监控的需求，则放一个监控器，然后告诉父节点自己这里放了一个监控器，可以监控父节点
            ans++; 
            return 2;
        }
        if(a == 2 || b == 2){
            return 0; // 子节点有监控器，自己已经被监控
        }
        return 1; //两个子节点都不要监控，则自己也不放监控器了，但是要告诉自己的父节点需要监控
    }
};
```

---
