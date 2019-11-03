# 127. 单词接龙

```c++
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		queue< string> q;
		q.push(beginWord);
		int dist = 0;//当前广度优先搜索到的距离为dist
		while (!q.empty()) {
			int size = q.size();
			dist++;
			for (int i = 0; i < size; i++) {//对
				string tmp = q.front();
				q.pop();
				for (int j = 0; j < wordList.size(); j++) { //遍历所有的待选字符
					int getDist = able(tmp, wordList[j]);
					if (getDist ==1) {
						if (wordList[j] == endWord)
							return dist+1;
						q.push(wordList[j]); //将该节点入队列，准备进行下一波广搜
						wordList.erase(wordList.begin() + j);  //删除该节点，减少重复搜索
						j--;

					}
					else if (getDist == 0) { //说明该节点和原始节点相同，直接删除
						wordList.erase(wordList.begin() + j);  //删除该节点，减少重复搜索
						j--;
					}
				}
			}
		}
		return 0;
	}

	int able(string &s1, string &s2) {
		int diffNum = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				diffNum++;
				if (diffNum > 1) {
					return -1;
				}
			}
		}
		if (diffNum == 0)
			return 0;
		return 1;
	}
};
```

---

最开始想用图的相关知识去做最短路径搜索，结果实现起来并不容易，并且容易超时，仔细分析一下，题中的节点之间的转化其实限制的很死，可以使用最广度优先搜索完成算法，每一次不断扩大搜索的步数，并且将出现在wordList中的节点删除掉。

这样做确实可以AC，但时间复杂度很一般，需要进行优化，主要优化的方法有两个。

## 优化方法1：使用双向搜索


两端搜索也就是说：“一头从beginWord转换为endWord，另外一头从endWord转换为beginWord。需要注意的是，搜索过程中`beginSet`和`endSet`都在不断扩大，实际算法执行时哪个集合的元素较少就搜索哪个集合。这样平衡的方法确实能减少时间复杂度。

## 优化方法2：使用改变字符，判断是否在集合中的方法来替代求距离的函数

这点没有想到，直观上来说复杂的好像没有改变，但是确实效果有点。

总体的代码如下：（使用set）

```c++
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordDict(wordList.begin(), wordList.end());
    if (wordDict.find(endWord) == wordDict.end()){
        return 0;//Not FOUND 404
    }
    unordered_set<string> beginSet{beginWord};
    unordered_set<string> endSet{endWord};
    int step = 1;
    for (; !beginSet.empty();){
        unordered_set<string> tempSet;
        ++step;
        for (auto s : beginSet) {
            wordDict.erase(s);
        }
        for (auto s : beginSet) {
            for (int i = 0; i < s.size(); ++i){
                string str = s;
                for (char c = 'a'; c <= 'z'; ++c){
                    str[i] = c;
                    if (wordDict.find(str) == wordDict.end()){
                        continue;
                    }
                    if (endSet.find(str) != endSet.end()){
                        return step;
                    }
                    tempSet.insert(str);
                }
            }
        }
        if (tempSet.size() < endSet.size()){
            beginSet = tempSet;
        } else {
            beginSet = endSet;
            endSet = tempSet;
        }
    }
    return 0;
}
```
