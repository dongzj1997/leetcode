# 105. 从前序与中序遍历序列构造二叉树

```c++
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这道题思路很简单，前序遍历的第一个节点一定是子树的根节点，根据这个根节点将中序遍历分割为左右两颗子树，根据左右两颗子树包含的元素个数再对前序遍历进行切割，递归得到左右两棵子树的根节点。

```c++
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { //前序遍历与中序遍历构造二叉树。
		int len = preorder.size();
		if (len == 0)
			return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
		if (len == 1) {
			return root;
		}
		int i = 0;
		while (1) {
			if (inorder[i] == preorder[0])
				break;
			i++;
		}
		vector<int> preorder_lo(preorder.begin()+1, preorder.begin()+i+1);
		vector<int> preorder_hi(preorder.begin() + i+1, preorder.end());
		vector<int> inorder_lo(inorder.begin(), inorder.begin()+i);
		vector<int> inorder_hi(inorder.begin()+i+1, inorder.end());

		root->left = buildTree(preorder_lo, inorder_lo);
		root->right = buildTree(preorder_hi, inorder_hi);

		return root;
	}
};
```

这种写法虽然只用了一个函数，看着比较简洁，但是最大的问题是再递归过程中要不断创建很多数组，导致时间复杂度和空间复杂度都十分的不好看。

比较好的方法是再使用一个单独的函数，每次递归时仅仅传递上下标。详细见下一题中的解法。
