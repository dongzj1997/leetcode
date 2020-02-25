# 面试题36. 二叉搜索树与双向链表

```c++
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

 

为了让您更好地理解问题，以下面的二叉搜索树为例：

 



 

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

 



 

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。

 

注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

注意：此题对比原题有改动。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

利用中序遍历得到节点的顺序，遍历的时候连接。

遍历完成后将首位节点连接起来。

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* head=NULL,* pre=NULL,* tail=NULL;
    Node* treeToDoublyList(Node* root) {
        if(!root) 
            return NULL;
        inorder(root);
        //连接头尾节点
        head->left=tail;
        tail->right=head;
        return head;
    }
    void inorder(Node* root){
        if(root==NULL) 
            return;
        inorder(root->left);
        if(pre==NULL) 
            head=root;
        else 
            pre->right=root;
        root->left=pre;
        pre=root;
        tail=root;
        inorder(root->right);
        return ;

    }
    
};
```

---



