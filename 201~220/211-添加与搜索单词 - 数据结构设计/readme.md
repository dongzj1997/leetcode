# 211. 添加与搜索单词 - 数据结构设计

```c++
设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
说明:

你可以假设所有单词都是由小写字母 a-z 组成的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-and-search-word-data-structure-design
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析

和之前的题大致相同，区别就是多了对 '.'的判断，如果遇到 '.'，则遍历当前节点的下一层，凡是遇到一个匹配项就返回true


```c++
for (int j = 0;j < 26; j++) {
    if (temp->child[j] != NULL && search2(word.substr(i + 1), temp->child[j]))
        return true;
}
```

对于'.'出现在最后一个的时候，做如下判断：

```c++
if (i == word.size()-1) {
    for (int j = 0; j < 26; j++) {
        if (temp->child[j] != NULL && temp->child[j]->end == true)
            return true;
    }
    return false;
```

---

最后整体代码：

执行用时 :96 ms, 在所有 cpp 提交中击败了95.08%的用户

```c++
class Node {
public:
	//char val;
	Node* child[26] = { NULL };
	bool end = false;  //这是不是某个元素的最终节点
	bool has_child = false;  //还有没有其他
};

class WordDictionary {
public:
	Node* root;
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Node();
	}

	/** Inserts a word into the trie. */
	void addWord(string word) {
		auto temp = root;
		for (int i = 0; i < word.size(); i++) {
			int offset = word[i] - 'a';
			if (temp->child[offset] == NULL) {  //此时这个节点还没有创建
				temp->child[offset] = new Node();
				temp->has_child = true;
				temp = temp->child[offset];
			}
			else {
				temp = temp->child[offset];
			}

		}
		temp->end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		auto temp = root;
		
		return search2(word, root);
	}
	bool search2(string word,Node *r) {
		auto temp = r;
		for (int i = 0; i < word.size(); i++) {
			if (word[i] == '.') {
				if (i == word.size()-1) {
					for (int j = 0; j < 26; j++) {
						if (temp->child[j] != NULL && temp->child[j]->end == true)
							return true;
					}
					return false;
				}
				for (int j = 0;j < 26; j++) {
					if (temp->child[j] != NULL && search2(word.substr(i + 1), temp->child[j]))
						return true;
				}
				return false;
			}
			else {
				int offset = word[i] - 'a';
				if (temp->child[offset] == NULL) {  //此时这个节点还没有创建
					return false;
				}
				else {
					temp = temp->child[offset];
				}
			}
		}
		return temp->end;
	}


};
```

---

以上
