# 846. 一手顺子

```c++
爱丽丝有一手（hand）由整数数组给定的牌。 

现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。

如果她可以完成分组就返回 true，否则返回 false。

 

示例 1：

输入：hand = [1,2,3,6,2,3,4,7,8], W = 3
输出：true
解释：爱丽丝的手牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
示例 2：

输入：hand = [1,2,3,4,5], W = 4
输出：false
解释：爱丽丝的手牌无法被重新排列成几个大小为 4 的组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hand-of-straights
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

1. 先使用map来统计每个数字出现的次数

2. 每次从map中取出一个最小值，然后从这个最小值出发来尝试组成一个顺子，如果组成失败，则直接返回false

3. 要注意一点，每个数字用过一次之后，要将这个数字出现次数-1，如果为0，则从map中删除这个数字

4. 这么做直到map中的数字被删光，返回true

时间复杂度为O(N*logN)。（也可以使用排序的方法，实现略麻烦一点）

```c++
class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int W) {
		map<int, int> mp;

		while (mp.size()) {
			auto head = *mp.begin();
			int t = head.first;
			mp[t]--;
			if (mp[t] == 0) mp.erase(t);
			for (int i = 1; i < W; i++) {
				if (mp[t + i] == 0) return false;
				mp[t + i]--;
				if (mp[t + i] == 0) mp.erase(t + i);
			}
		}

		return true;
	}
};

```

---

要注意一点，热评中的方法有潜在的bug

```java
public boolean isNStraightHand(int[] hand, int w) {
        if(hand.length % w != 0)
            return false;
        int[] array = new int[w];
        for (int i : hand) {
            array[i % w]++;
        }
        for(int i = 0; i < w - 1; i++) { 
            //若是顺子，array的每一元素理应是相等的
            if(array[i] != array[i+1])
                return false;
        }
        return true;
    }
```

将原始数值映射回`W`，看似很巧妙，但是如果`W = 3` ， `hand = { 1，5，6}` 的时候也返回`true`

所以这种方法只能判断必要性，不能判断充分性。
