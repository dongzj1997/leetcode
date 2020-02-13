# 面试题 10.05. 稀疏数组搜索

```c++
稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。

示例1:

 输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
 输出：-1
 说明: 不存在返回-1。
示例2:

 输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
 输出：4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sparse-array-search-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

**首个通过**

本来信心满满准备一次提交就过的，结果还是用了3次 …………

相对于普通二分查找，还需要注意如下几点：

left 和right可能对应的是空值，还需要人为的判断并缩小边界。
计算出的mid可能对应的也是空值，这里的策略是将mid向右偏，直到不为空或者接触到右边界，如果到达右边界，说明mid和right这一段没有我们想要的值，所以将right更新为最初的mid即可。
细节比较多,注意盯住边界。


```c++
class Solution {
public:
	int findString(vector<string>& words, string s) {
		int left = 0, right = words.size() - 1;
		while (left <= right) {
			if (words[left].size() == 0) {
				left++;
				continue;
			}
			if (words[right].size() == 0) {
				right--;
				continue;
			}
			int mid = (right + left) / 2;
			while (words[mid].size() == 0) {
				mid++;
				if (mid == right) {
					right = (right + left) / 2;
					continue;
				}
			}

			if (words[mid] == s)
				return mid;
			else if (words[mid] > s) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return -1;
	}
};
```

---

![img](./1.jpg)

