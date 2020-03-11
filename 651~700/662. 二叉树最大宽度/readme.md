# 662. 二叉树最大宽度

```c++

给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。

每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。

示例 1:

输入: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

输出: 4
解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
示例 2:

输入: 

          1
         /  
        3    
       / \       
      5   3     

输出: 2
解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
示例 3:

输入: 

          1
         / \
        3   2 
       /        
      5      

输出: 2
解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
示例 4:

输入: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
输出: 8
解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
注意: 答案在32位有符号整数的表示范围内。
```

---

假设满二叉树的特点： 

根节点所在的位置为i, 则任意位于i节点的左右子节点的`index`为`2*i`, `2*i+1`

根据上述性质对节点进行编号，为`index`
用一个数组保存每层的最左左端点的`index`, 遍历时，每次将节点的`index`与该层最左端点的`index`值比较，选出最大的。

结果可能会非常大，取模避免移除（会存在潜在的bug，但是题目中给了答案在32位内，所以正确答案不会出bug）

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
    int ans =0;
    vector<int> v1;
    int M = 1e14;
    int widthOfBinaryTree(TreeNode* root) {
        helper(root, 1, 1);
        return ans+1;
    }
    void helper(TreeNode* root, int depth, int index){
        if(!root) return;
        index %= M;
        if(v1.size() < depth) v1.push_back(index);
        ans = max(ans, index - v1[depth-1]);
        helper(root->left, depth+1, index*2);
        helper(root->right, depth+1, index*2+1);
    }
};
```

---



