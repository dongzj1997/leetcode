# 面试题07. 重建二叉树

```c++
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
 

限制：

0 <= 节点个数 <= 5000

 

注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

递归大法好。

c++的数组分割功能有点烂，宁愿用下标来表示。

```c++
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode* ans = helper(0, preorder.size() - 1, 0, inorder.size() - 1, preorder,inorder);
        return ans;
	}

	TreeNode* helper(int pre_left, int pre_right, int in_left, int in_right, vector<int>& preorder,vector<int>& inorder) {
		if (pre_right < pre_left)
			return nullptr;
		TreeNode* newroot = new TreeNode{ preorder[pre_left] };
		for (int i = in_left; i <= in_right; i++) {
			if (preorder[pre_left] == inorder[i]) {
				int t = i - in_left;
				newroot->left = helper(pre_left + 1, pre_left + t, in_left, i - 1, preorder, inorder);
				newroot->right = helper(pre_left + t + 1, pre_right, i + 1, in_right, preorder, inorder);
				break;
			}
		}
		return newroot;
	}
};
```

---



