有两种思路

第一种是利用排序二叉树的中序遍历为有序数组的特性，先将树中序遍历，然后保证遍历时的val值递增即可。代码如下：

（需要注意的一点是用  pre && pre->val 来启动算法，初始化第一个值）

```c++
class Solution {
public:
    TreeNode* pre;
    bool isValidBST(TreeNode* root) {
        //方法一 非递归
        stack<TreeNode*> s;
        TreeNode* cur = root;  
        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }else{
                cur = s.top();
                s.pop();
                if(pre && pre->val >= cur->val) return false;
                pre = cur;
                cur = cur->right;
            }
        }
        return true;
        
        //方法二 递归
        if(root == NULL)
            return true;
        if(!isValidBST(root->left)){
            return false;
        }
        if(pre && pre->val >= root->val)
            return false;
        pre = root;
        if(!isValidBST(root->right))
            return false;
        return true;
            
    }
};
```

第二种方法是人为的设置最大最小值，然后递归或者迭代:

（需要注意的一点是 需要使用一个不可能在正常情况下出现的lower和upper值来跳过最左节点的最小值判断，和最右节点的最大值判断，这里使用的是 LLONG_MIN, LLONG_MAX）

```C++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return dfs(root, LLONG_MIN, LLONG_MAX);
	}

	bool dfs(TreeNode* root,long long lower, long long upper) { //定义上下边界
		if (root == NULL)
			return true;
		long long v = root->val;
		if (lower != LLONG_MIN && v <= lower)
			return false;
		if (upper != LLONG_MAX && v >= upper)
			return false;
		return dfs(root->left, lower ,v) && dfs(root->right,v, upper);
		//如果检查左子树，则值的上界变小，下界还是原来的下界，同理，检查右子树时，上界不变，最小值（下界）变大
	}
};
```