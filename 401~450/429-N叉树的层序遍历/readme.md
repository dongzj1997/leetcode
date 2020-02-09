# 429. N叉树的层序遍历

```c++
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。

例如，给定一个 3叉树 :

 



 

返回其层序遍历:

[
     [1],
     [3,2,4],
     [5,6]
]
 

说明:

树的深度不会超过 1000。
树的节点总数不会超过 5000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这个题没创意

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int l=q.size();
            vector<int>tmp;
            for(int i=0;i<l;i++){
                Node* t=q.front();
                q.pop();
                tmp.push_back(t->val);
                for(auto it :t->children){
                    q.push(it);
                }
            }
            ans.push_back(tmp);
        }   
        return ans;
    }
};
```

---



