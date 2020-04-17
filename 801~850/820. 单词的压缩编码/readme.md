# 820. 单词的压缩编码

```c++
给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。

对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

 

示例：

输入: words = ["time", "me", "bell"]
输出: 10
说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 

提示：

1 <= words.length <= 2000
1 <= words[i].length <= 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/short-encoding-of-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 方法1，先逆序后排序

```c++
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &word : words){
            reverse(word.begin(),word.end());
        }
        sort(words.begin(),words.end());
        
        int ans=0;
        for(int i=0;i<words.size()-1;i++){
            int len=words[i].size();
            if(words[i]==words[i+1].substr(0,len)) 
                continue;
            ans += len+1;
        }
        return ans+words.back().size()+1;
    }
};
```

## 方法2，字典树（速度略慢）

```c++
class Node {
public:
    char c;
    vector<Node*> ch = vector<Node*>(26, NULL);
};

class Tire {
public:
    Node* root;
    Tire() {
        root = new Node();
    }
    int ins(string s) {
        Node* cur = root;
        bool isNew = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if ((cur->ch)[c] == NULL) {
                isNew = 1;
                (cur->ch)[c] = new Node;
            }
            cur = (cur->ch)[c];
        }
        return isNew ? s.size() + 1 : 0;
    }
};



class Solution {
public:
    static bool cmp(string a, string b) {
        return a.size() > b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int ans = 0;
        Tire* T = new Tire();
        for (auto s : words) {
            ans += T->ins(s);
        }
        return ans;
    }
};
```

---



