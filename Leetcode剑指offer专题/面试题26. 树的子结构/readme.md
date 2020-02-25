# 面试题26. 树的子结构

```c++
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false
示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true
限制：

0 <= 节点个数 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof
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
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr)
			return false;
		if (A->val == B->val) {
			return helper(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
		}
		else {
			return isSubStructure(A->left, B) || isSubStructure(A->right, B);
		}
	}

	bool helper(TreeNode* A, TreeNode* B) {
		if (A->val == B->val) {
			if (B->left == nullptr && B->right == nullptr)
				return true;
			else {
				bool left, right;
				if (B->left) {
					left = A->left && helper(A->left, B->left);
				}
				if (B->right) {
					right = A->right && helper(A->right, B->right);
				} //可以稍加修改，如果left为假，直接发返回假，就不用遍历右边的了

				return left && right;
			}
		}
		else
			return false;
	}
};
```

---



