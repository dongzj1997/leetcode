# 102. 二叉树的层次遍历

```c
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

有多种方法，首先想到的是使用两个队列，队列1遍历，队列二储存下一层的节点，在队列1为空时，交换两队列，进行下一层的遍历，代码：

```C++
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr) {
			return vector<vector<int>>{};
		}
		vector<vector<int>> ans;
		queue<TreeNode*> S1 = {};
		queue<TreeNode*> S2 = {};
		S1.push(root);

		while (!S1.empty()) {
			vector<int> layer = {};
			while (!S1.empty()) {
				
				TreeNode* t = S1.front();
				layer.push_back(t->val);
				if (t->left != NULL)
					S2.push(t->left);
				if (t->right != NULL)
					S2.push(t->right);
				S1.pop();

			}
			queue<TreeNode*> t = S1;
			S1 = S2;
			S2 = t;
			ans.push_back(layer);
		}
		return ans;
	}
};
```

另一种方法是使用计数的方法来控制层数

```C++
while(Q.empty()==0){
    vector<int> a;
    int width=Q.size();
    for(int i=0;i<width;i++){
        p=Q.front();
        a.push_back(p->val);
        Q.pop();
        if(p->left) Q.push(p->left);
        if(p->right) Q.push(p->right);
    }
    res.push_back(a);
}
```

还可以通过递归是手动记录层次信息的方法来解题：
```python
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        if not root:
            return levels
        
        def helper(node, level):
            # start the current level
            if len(levels) == level:
                levels.append([])

            # append the current node value
            levels[level].append(node.val)

            # process child nodes for the next level
            if node.left:
                helper(node.left, level + 1)
            if node.right:
                helper(node.right, level + 1)
            
        helper(root, 0)
        return levels

作者：LeetCode
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-de-ceng-ci-bian-li-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```