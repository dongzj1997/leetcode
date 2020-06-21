# 1028. 从先序遍历还原二叉树

```c++
我们从二叉树的根节点 root 开始进行深度优先搜索。

在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出 S，还原树并返回其根节点 root。

 

示例 1：



输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]
示例 2：



输入："1-2--3---4-5--6---7"
输出：[1,2,5,3,null,6,null,4,null,7]
示例 3：



输入："1-401--349---90--88"
输出：[1,401,null,349,88,90]
 

提示：

原始树中的节点数介于 1 和 1000 之间。
每个节点的值介于 1 和 10 ^ 9 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-a-tree-from-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

二叉树天然是递归

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
    int pos;
    vector<pair<int,int>> vc;
    TreeNode* recoverFromPreorder(string S) {
        pos = 0;
        int len = S.size();
        int cnt = 0, val = 0, i = 0;
        while(i<len){
            while(S[i] =='-'){
                i++;
                cnt++;
            }
            while(i < len && S[i] != '-'){
                val *= 10;
                val += (S[i] -'0');
                i++;
            }
            vc.push_back({cnt,val});
            cnt = 0;
            val = 0;
        }
        return hp(0);
    }

    TreeNode* hp( int depth){
        if(pos == vc.size()) return NULL;
        auto & pair = vc[pos];
        if(pair.first == depth){
            pos++;
            TreeNode * root = new TreeNode(pair.second);
            root->left = hp(depth+1);
            root->right = hp(depth+1);
            return root;
        }
        return NULL;
    }
};
```

---

