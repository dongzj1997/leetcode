# 面试题11. 旋转数组的最小数字

```c++
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0
注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

注意当`numbers[mid] == numbers[right]`时，只能排除掉最右边的数组，下一轮搜索区间是 [left, right - 1]


```c++
class Solution {
public:
	int minArray(vector<int>& numbers) {
        int len = numbers.size();
        if (len == 0) {
            return 0;
        }
        int left = 0;
        int right = len - 1;
        while (left < right) {
            int mid = (left + right)/2;
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            }
            else if (numbers[mid] == numbers[right]) {
                right = right - 1;
            }
            else {
                // mid 的右边一定不是最小数字，但mid 有可能是
                right = mid;
            }
        }
		return numbers[left];
    }    
};
```

---



