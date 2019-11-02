# 114. 二叉树展开为链表

```c++
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL)
			return;
		flatten(root->left);
		flatten(root->right);

		TreeNode* tmp1 = root->left;
		TreeNode* tmp2 = root->right;

		root->left =NULL; //将原来的左分支置为空
		//根据递归，此时的左分支一定只有右子树，左子树都为NULL；

		root->right = tmp1; //插入

		while (root->right) { //找叶节点
			root = root->right;
		}
		root->right = tmp2; //链接
	}
};
```

---

采用递归后续遍历的方法，后续遍历完毕以后将左节点加到其右节点上，不断递归即可