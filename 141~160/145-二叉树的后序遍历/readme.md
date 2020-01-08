# 145. 二叉树的后序遍历

```c++
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析

### 解法1，使用“倒着的”先序遍历

因为先序是“根左右”而后序是“左右根”，所以模仿先序生成“根右左”再反转输出就是“左右根了”

将新节点直接插入要输出的最前一个

![mg](./1.bmp)

```c++
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> s;

		auto t = root;
		while (t) { //先将最左边的入栈
			ans.insert(ans.begin(), t->val); //后序遍历
			s.push(t);
			t = t->right; //注意这里要插入右节点 才能生成（根右左）
		}

		while (!s.empty()) { //当栈不为空时
			t = s.top();
			s.pop();
			t = t->left;

			while (t) {
				ans.insert(ans.begin(), t->val); //后序遍历
				s.push(t);
				t = t->right; //同理
			}
		}
		return ans;
	}
};
```


另一种写法：

```C++

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk1,stk2;
        if(root==NULL)
            return res;
        stk1.push(root);
        TreeNode* temp;
        while(!stk1.empty()){
            temp=stk1.top();
            stk1.pop();
            stk2.push(temp);
            if(temp->left!=NULL)
                stk1.push(temp->left);  //注意先序的时候是先右后左
            if(temp->right!=NULL)
                stk1.push(temp->right); //后续先左后右
        }
        while(!stk2.empty()){ //倒序输出
            res.push_back(stk2.top()->val);
            stk2.pop();
        }
        return res;
    }
} ;

```

### 解法2（使用一个pre指针辅助判断）(可以实时输出，不需要缓存结果)（*********）


比起前序与中序遍历，后续非递归遍历多了一个辅助变量pre来判断右节点是否被访问过

（因为后序遍历总是从右节点上来的，所以将上一个输出的节点设置为pre节点，然后使用pre == curr->right来判断某个节点的右节点是否都已经输出完毕）

```C++
stack<TreeNode*> mystack;
vector<int> ans;
TreeNode* curr = root;
TreeNode* pre = NULL;

while(curr || !mystack.empty())
{
    while(curr)
    {
        mystack.push(curr);
        curr = curr->left;
    }
    curr = mystack.top();
    
    //若右节点已经访问过或者没有右节点  则输出该节点值
    if(!curr->right || pre == curr->right){
        mystack.pop();
        ans.push_back(curr->val);    
        pre = curr;
        curr = NULL;
    }else{
        curr = curr->right;
        pre = NULL;
    }
}
return ans;

/*
作者：jjjjjz
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/c-by-jjjjjz-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
```

---



