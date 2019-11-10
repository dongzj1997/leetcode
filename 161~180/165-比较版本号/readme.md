# 165. 比较版本号

```c++
比较两个版本号 version1 和 version2。
如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。

你可以假设版本字符串非空，并且只包含数字和 . 字符。

 . 字符不代表小数点，而是用于分隔数字序列。

例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。

你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和 4。其第三级和第四级修订号均为 0。
 

示例 1:

输入: version1 = "0.1", version2 = "1.1"
输出: -1
示例 2:

输入: version1 = "1.0.1", version2 = "1"
输出: 1
示例 3:

输入: version1 = "7.5.2.4", version2 = "7.5.3"
输出: -1
示例 4：

输入：version1 = "1.01", version2 = "1.001"
输出：0
解释：忽略前导零，“01” 和 “001” 表示相同的数字 “1”。
示例 5：

输入：version1 = "1.0", version2 = "1.0.0"
输出：0
解释：version1 没有第三级修订号，这意味着它的第三级修订号默认为 “0”。
 

提示：

版本字符串由以点 （.） 分隔的数字字符串组成。这个数字字符串可能有前导零。
版本字符串不以点开始或结束，并且其中不会有两个连续的点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compare-version-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class Solution {
public:
	int compareVersion(string version1, string version2) {
		version1 += '.';
		version2 += '.';
		int len1 = version1.size();
		int len2 = version2.size();
		
		int start1 = 0, start2 = 0;
		int end1 = 0, end2 = 0;
		while (end1 < len1  || end2 < len2 ) {
			int val1 = 0, val2 = 0;
			if (end1 < len1 ) {
				while (version1[end1] != '.') end1++;
				val1 = atoi(version1.substr(start1, end1 - start1).data());
			}
			if (end2 < len2 ) {
				while (version2[end2] != '.') end2++;
				val2 = atoi(version2.substr(start2, end2 - start2).data());
			}

			if (val1 > val2) {
				return 1;
			}
			else if (val1 < val2)
				return -1;
			else {
				end1++;
				end2++;
				start1 = end1 ;
				start2 = end2 ;
			}
		}
		return 0;
	}
};

```

---

先将每个字符串的末尾都加一个'.'，数据就变得很规整，方便比较。
