# 987. 二叉树的垂序遍历

```c++
给定二叉树，按垂序遍历返回其结点值。

对位于 (X, Y) 的每个结点而言，其左右子结点分别位于 (X-1, Y-1) 和 (X+1, Y-1)。

把一条垂线从 X = -infinity 移动到 X = +infinity ，每当该垂线与结点接触时，我们按从上到下的顺序报告结点的值（ Y 坐标递减）。

如果两个结点位置相同，则首先报告的结点值较小。

按 X 坐标顺序返回非空报告的列表。每个报告都有一个结点值列表。

 

示例 1：



输入：[3,9,20,null,null,15,7]
输出：[[9],[3,15],[20],[7]]
解释： 
在不丧失其普遍性的情况下，我们可以假设根结点位于 (0, 0)：
然后，值为 9 的结点出现在 (-1, -1)；
值为 3 和 15 的两个结点分别出现在 (0, 0) 和 (0, -2)；
值为 20 的结点出现在 (1, -1)；
值为 7 的结点出现在 (2, -2)。
示例 2：



输入：[1,2,3,4,5,6,7]
输出：[[4],[2],[1,5,6],[3],[7]]
解释：
根据给定的方案，值为 5 和 6 的两个结点出现在同一位置。
然而，在报告 "[1,5,6]" 中，结点值 5 排在前面，因为 5 小于 6。
 

提示：

树的结点数介于 1 和 1000 之间。
每个结点值介于 0 和 1000 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这题最大的问题是，如果两个结点位置相同，则首先报告的结点值较小，则说明单纯的遍历已经解决不了问题了 ， 必须进行排序。

使用层序遍历可以得到一个近似的结果，但是无法处理节点位置相同，还在同一层的情况。

所以每一层用一个辅助字典tmp，遍历完每一层以后，将这个字典进行排序，然后将排序的结果插入到真正的大字典当中。

遍历完所用层以后，将大字典的结果输入到ans中，就是最后的结果。

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int,vector<int>> mp;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size()){
            int len = q.size();

            map<int,vector<int>> tmp;

            while(len--){
                auto t = q.front();
                q.pop();
                tmp[t.second].push_back(t.first->val);
                if(t.first->left != nullptr)
                    q.push({t.first->left, t.second - 1 });
                if(t.first->right != nullptr)
                    q.push({t.first->right, t.second + 1 });
            }
            for(auto &i : tmp){ //同层，且重叠在一列上面，按照大小排序
                int val = i.first;
                sort(i.second.begin(),i.second.end());
                for(auto j : i.second){
                    mp[val].emplace_back(j);
                }
            }
        }
        for(auto x: mp){
            ans.emplace_back(x.second);
        }

        return ans;
    }
};
```

---


还有一种方法， 就是将节点的值稍作修改，使之记录层序层序信息，确保了层序大的节点的值一定会比层序小的值大。

具体做法是先序遍历的时候同时记录层数，然后将节点的值*层数*10000

最后生成结果的时候直接将结果%10000就行（此时虽然不知道是多少层，但是%10000后就与层数无关了，理解一下）

来自[@guoshuhong]

```c++
class Solution {
public:
    map<int,set<int>> m;
    void helper(TreeNode* p,int x,int y){
        if(!p) return;
        m[x].insert(y*10000+p->val);//坐标值在高位，节点的值在低位（如果两个节点的坐标值也相同节点值也相同可考虑multiset,这里没有这种情况）
        helper(p->left,x-1,y+1);//y+1是因为排序时y值小的在前面
        helper(p->right,x+1,y+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root,0,0);
        vector<vector<int>> ans;
        for(auto x:m){
            vector<int> curr;
            for(auto y:x.second) curr.push_back(y%10000);
            ans.push_back(curr);
        }
        return ans;
    }
};
```