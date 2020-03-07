# 589. N叉树的前序遍历

```c++
给定一个 N 叉树，返回其节点值的前序遍历。

例如，给定一个 3叉树 :
```

![1](./narytreeexample.png)

```c++
返回其前序遍历: [1,3,5,6,2,4]。

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?

通过次数19,265提交次数26,663

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

借助栈，每次倒着将弹出节点的所有孩子都入栈，这样才能做到前序。

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> s;
        vector<int> ans;
        if(!root) return ans; 
        s.push(root);
        while(!s.empty()){
            Node* t = s.top();
            s.pop();
            ans.push_back(t->val);
            int len = (t->children).size();
            
            for(int i = len-1;i>=0;i--)
                s.push((t->children)[i]);
        }
        return ans;
    }
};
```

---



