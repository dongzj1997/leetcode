# 692. 前K个高频单词

```c++
给一非空的单词列表，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

示例 1：

输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
 

示例 2：

输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。
 

注意：

假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
输入的单词均由小写字母组成。
 

扩展练习：

尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

优先级队列经典用法

```c++
struct cmp
{
	bool operator()(const pair<int, string>& a, const pair<int, string>& b){
		if(a.first != b.first) return a.first > b.first;
		return a.second < b.second;
		
	}
};

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> mp;
		for (auto s : words) {
			mp[s]++;
		}
		vector<pair<int, string> > p;
		for (auto d : mp) {
			p.push_back({ d.second, d.first });
		}
		priority_queue<pair<int, string>, vector<pair<int, string> >, cmp > q;
		for (auto tq : p) {
			if(q.size() < k || q.top().first <= tq.first){
				q.push(tq);
			}
			if (q.size() > k)
				q.pop();
		}

		vector<string> ans;
		while (q.size()!= 0) {
			ans.push_back(q.top().second);
			q.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
```

---



