# 1032. 字符流

```c++
按下述要求实现 StreamChecker 类：

StreamChecker(words)：构造函数，用给定的字词初始化数据结构。
query(letter)：如果存在某些 k >= 1，可以用查询的最后 k个字符（按从旧到新顺序，包括刚刚查询的字母）拼写出给定字词表中的某一字词时，返回 true。否则，返回 false。
 

示例：

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // 初始化字典
streamChecker.query('a');          // 返回 false
streamChecker.query('b');          // 返回 false
streamChecker.query('c');          // 返回 false
streamChecker.query('d');          // 返回 true，因为 'cd' 在字词表中
streamChecker.query('e');          // 返回 false
streamChecker.query('f');          // 返回 true，因为 'f' 在字词表中
streamChecker.query('g');          // 返回 false
streamChecker.query('h');          // 返回 false
streamChecker.query('i');          // 返回 false
streamChecker.query('j');          // 返回 false
streamChecker.query('k');          // 返回 false
streamChecker.query('l');          // 返回 true，因为 'kl' 在字词表中。
 

提示：

1 <= words.length <= 2000
1 <= words[i].length <= 2000
字词只包含小写英文字母。
待查项只包含小写英文字母。
待查项最多 40000 个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stream-of-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

这题的理解题目的难度甚至超过了前缀树（倒着的）本身。

```c++

class StreamChecker {
public:
    struct TreeNode
    {
        bool end = false;;
        TreeNode* child[26] = {0};
    };

    TreeNode* root = new TreeNode();
    string s ="";

    StreamChecker(vector<string>& words) {
        for(string &t : words){
            TreeNode*node = root;
            for(int j=t.size()-1;j>=0;j--)
            {
                int offs=t[j]-'a';
                if(!node->child[offs]) 
                    node->child[offs] = new TreeNode();
                node = node->child[offs];
            }
            node->end = true;
        }
    }
    
    bool query(char letter) {
        s.push_back(letter);
        TreeNode*node = root;
        for(int i=s.size()-1;i>=0;i--)
        {
            int offs=s[i]-'a';
            if(!node->child[offs])
                return false;
            if(node->child[offs]->end) 
                return true;
            node=node->child[offs];
        }
        if(node->end) 
            return true; 
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
```

---

