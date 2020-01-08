# 260. 只出现一次的数字 III

```c++
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :

输入: [1,2,1,3,2,5]
输出: [3,5]
注意：

结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题

先将数组中的所有数全部异或一次, 其结果就相当于这两个数异或，结果中为1的位表示这两个数在此为上不同, 一个为0, 一个为1。

任意取一个不同位，由此将数组中的元素分成两部分,重新遍历, 求两个异或值。

关键是如何求那个不同的位，根据补码的特性可以使用`int mask = s & (-s);`。

```c++
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int s = 0;
		for (int t : nums) {
			s ^= t;
		}

		//取两个出现一次的数32位中 第一次不同位的位置为mask，据此来讲nums数组分类
		int mask = s & (-s); //补码，相当于 ~1 +1  这样除了从右往左第一次bit位相同之外，其他都不同
		int a = 0, b = 0;
		for (int t : nums) {
			if ((mask & t) == 0) {  //注意优先级，一定要对位运算加括号
				a ^= t;
			}
			else {
				b ^= t;
			}
		}
		
		vector<int> ans;
		ans.push_back(a);
		ans.push_back(b);
		return ans;
	}
};
```

---



