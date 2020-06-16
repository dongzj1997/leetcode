# 1079. 活字印刷

```c++
你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。

注意：本题中，每个活字字模只能使用一次。

 

示例 1：

输入："AAB"
输出：8
解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
示例 2：

输入："AAABBC"
输出：188
 

提示：

1 <= tiles.length <= 7
tiles 由大写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-tile-possibilities
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 中二解法

每次从头开始摘取一个字符，然后拼接到已有的集合中，组从新的集合。

如果字符串长度为n，那么摘取n次就能生成结果，

但是如果是“AAB”,的字符串，用这个方法会生成“AAA”的结果，所以插入时再判断一下是不是所有字符都够用。

速度超级慢，击败5%。

```c++
class Solution {
public:
	int numTilePossibilities(string tiles) {
		unordered_set<string> st;
        vector<int> cnt(26,0);
        int len = tiles.size();
        for(int i=0;i<len;i++){
            cnt[tiles[i] - 'A']++;
        }
		st.insert("");

		for (int i = 0; i < len; i++) {
			unordered_set<string> stt = st;
			for (int j = 0; j < len; j++) {
				for (auto c: stt) {
                    string t = c + tiles[j];
                    vector<int> ccnt = cnt;
                    bool f = true;
                    for(int k=0;k<t.size();k++){
                        ccnt[ t[k] - 'A']--;
                        if( ccnt[ t[k] - 'A'] < 0){
                            f = false;
                            break;
                        }
                    }
                    if(f)
					    st.insert(t);
				}
			}
		}
        // for(auto c :st){
        //     cout <<c <<endl;
        // }
		return st.size() -1 ;
	}
};
```

---

## 高效解法

```c++
class Solution {
public:
    int ans = 0;
    int numTilePossibilities(string tiles) {
        int map[26] = {0};
        for(int i=0;i<tiles.size();i++)
        {
            map[tiles[i]-'A']++;
        }
        dfs(map);
        return ans;
    }
    void dfs(int map[])
    {
        for(int j=0;j<26;j++)
        {
            //直接算出A的个数而不会去管A的顺序。
            if(map[j])
            {
                map[j]--;
                ans++;
                dfs(map);
                map[j]++;
            }
        }
        return;
    }
};

```