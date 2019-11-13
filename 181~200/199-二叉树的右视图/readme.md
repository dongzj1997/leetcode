# 199-二叉树的右视图

```c++
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

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
vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	if (!root) 
        return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size();
		res.push_back(q.front()->val);
		while (size--)
		{
			TreeNode* temp = q.front();
			q.pop();
			if (temp->right) 
                q.push(temp->right);
			if (temp->left) 
                q.push(temp->left);
		}
	}
	return res;
}
};
```

---

层序遍历时输出每一层的最后一个数就行
