# 面试题37. 序列化二叉树

```c++
请实现两个函数，分别用来序列化和反序列化二叉树。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

不是很难

```c++
class Codec {
public:
	stringstream ss;
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		helper1(root);
		return ss.str();

	}
	void helper1(TreeNode* root) {
		if (root == NULL) 
			ss << "# ";
		else {
			ss << to_string(root->val) + " ";
			helper1(root->left);
			helper1(root->right);
		}
	}


	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		ss = stringstream(data);
		return helper2();
	}

	TreeNode* helper2() {
		string t;
		ss >> t;
		TreeNode* ans;
		if (t[0] == '#') {
			ans = NULL;
		}
		else {
			ans = new TreeNode(stoi(t));
			ans->left = helper2();
			ans->right = helper2();
		}
		return ans;
	}
};
```

---



