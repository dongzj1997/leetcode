# 133. 克隆图

```c++
给定无向连通图中一个节点的引用，返回该图的深拷贝（克隆）。图中的每个节点都包含它的值 val（Int） 和其邻居的列表（list[Node]）。

示例：
![img1](./113_sample.png)

输入：
{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}

解释：
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。
 

提示：

节点数介于 1 到 100 之间。
无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
必须将给定节点的拷贝作为对克隆图的引用返回。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/clone-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node)   
            return nullptr;
        if(mp.count(node))  //旧节点已经被收录，则返回与之对应的新节点
            return mp[node];
        Node* c = new Node(node -> val);
        mp[node] = c;
        for(int i = 0; i < node -> neighbors.size(); i++){
            if(node -> neighbors[i])
                c -> neighbors.push_back(cloneGraph(node -> neighbors[i]));
        }
        return c;
    }
};

```

---

使用深度优先，设置一个字典，存储新旧节点地址的对应关系，每次递归时如果该节点已经创建，则返回该节点的新位置（地址），如果该节点还没有创建，则使用`c -> neighbors.push_back(cloneGraph(node -> neighbors[i]));`递归地创建和它有关的所有节点。
