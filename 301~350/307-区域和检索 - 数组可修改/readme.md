# 307. 区域和检索 - 数组可修改

```c++
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。

示例:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
说明:

数组仅可以在 update 函数下进行修改。
你可以假设 update 函数与 sumRange 函数的调用次数是均匀分布的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-mutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析

使用线段树，构造和更新线段树并不难，主要是注意理解区域和检索时的代码：

```java
public int sumRange(int l, int r) {
    // get leaf with value 'l'
    l += n;
    // get leaf with value 'r'
    r += n;
    int sum = 0;
    while (l <= r) {
        if ((l % 2) == 1) {
           sum += tree[l];
           l++;
        }
        if ((r % 2) == 0) {
           sum += tree[r];
           r--;
        }
        l /= 2;
        r /= 2;
    }
    return sum;
}

//作者：LeetCode
//链接：https://leetcode-cn.com/problems/range-sum-query-mutable/solution/qu-yu-he-jian-suo-shu-zu-ke-xiu-gai-by-leetcode/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

```c++


class NumArray {
public:
	vector<int> tree; //用数组表示的树，节点i（从1开始）左子节点和右子节点分别存储在索引为 2i和 2i+1 的元素处。
	int len=0;

	void buildTree(vector<int>& nums) {
		for (int i = len, j = 0; i < 2 * len; i++, j++) //先构造叶子节点
			tree[i] = nums[j];
		for (int i = len - 1; i > 0; i--) //倒着构造之前的和节点
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	NumArray(vector<int>& nums) {
		if (nums.size() > 0) {
			len = nums.size();
			tree = vector<int>(len * 2);
			buildTree(nums);
		}
	}



	void update(int i, int val) {
		tree[i + len] = val;
		for (int t = (len + i) / 2; t > 0; t=t/2) 
			tree[t] = tree[t * 2] + tree[t * 2 + 1];
	}

	int sumRange(int i, int j) {
		
		int left = i;
		int right = j;

		left += len;
		right += len;
		int sum = 0;

		while (left <= right) {   /******  核心代码  *******/
			if ((left % 2) == 1) {
				sum += tree[left];
				left++;
			}
			if ((right % 2) == 0) {
				sum += tree[right];
				right--;
			}
			left /= 2;
			right /= 2;
		}
		return sum;
	}

};
```

---

