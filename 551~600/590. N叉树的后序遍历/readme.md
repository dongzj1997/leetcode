# 590. N叉树的后序遍历

```c++
给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :

 



 

返回其后序遍历: [5,6,3,2,4,1].

 

说明: 递归法很简单，你可以使用迭代法完成此题吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

先序遍历，入栈的时候是倒着入栈。

后序遍历就是 入栈的时候正序入栈，然后最后做一次翻转。

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
    vector<int> postorder(Node* root) {
        stack<Node*> s;
        vector<int> ans;
        if(!root) return ans; 
        s.push(root);
        while(!s.empty()){
            Node* t = s.top();
            s.pop();
            ans.push_back(t->val);
            int len = (t->children).size();
            
            for(int i = 0;i<len;i++)
                s.push((t->children)[i]);

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```

---



