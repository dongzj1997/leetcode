# 677. 键值映射

```c++
实现一个 MapSum 类里的两个方法，insert 和 sum。

对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。

对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。

示例 1:

输入: insert("apple", 3), 输出: Null
输入: sum("ap"), 输出: 3
输入: insert("app", 2), 输出: Null
输入: sum("ap"), 输出: 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/map-sum-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

字典树的普通应用，就是会出现插入的字符串是相同的有点没想到。

```c++
class Tire {
public:
    bool isEnd = false;
    int score = 0;
    Tire * child[26] = {NULL};
};

class MapSum {
public:
    Tire * T;
    /** Initialize your data structure here. */
    MapSum() {
        T = new Tire();
    }
    
    void insert(string key, int val) {
        auto cur = T;
        for(char c: key){
            if(cur->child[c-'a'] == NULL){
                cur->child[c-'a'] = new Tire();
            }
            cur = cur->child[c-'a'];
            //cur->score += val;
        }
        cur->score = val;
        cur->isEnd = true;
    }
    int sumHelper(Tire *ptr){
        int t= 0;
        if(!ptr) return 0;
        if(ptr->isEnd) t += ptr->score;
        for(int i=0;i<26;i++){
            if(ptr->child[i])
                t +=sumHelper(ptr->child[i]);
        }
        return t;
    }
    int sum(string prefix) {
        auto cur = T;
        for(char c: prefix){
            if(cur->child[c-'a'] == NULL){
                return 0;
            }
            cur = cur->child[c-'a'];
        }
        return sumHelper(cur);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
```

---



