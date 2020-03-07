# 520. 检测大写字母

```c++

给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。

示例 1:

输入: "USA"
输出: True
示例 2:

输入: "FlaG"
输出: False
```

---

一个小题居然提交了3次

```c++
class Solution {
public:
    bool detectCapitalUse(string word) {
        int status = 0;
        int len = word.size();
        if(len <= 1) return true;
        if(word[0] >='a' )
            status = 0; //leetcode
        else if(word[1] >= 'a')
            status = 1; // Google
        else
            status = 2; // USA
        for(int i =1;i<len;i++){
            if(status != 2 ){
                if(word[i] < 'a')
                    return false;
            }else{
                if(word[i] >= 'a')
                    return false;
            }
        }
        return true;
    }
};
```

---



