# 912. 排序数组

```c++
给定一个整数数组 nums，将该数组升序排列。

 

示例 1：

输入：[5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 

提示：

1 <= A.length <= 10000
-50000 <= A[i] <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

写了一个快排，一个归并

还是要多练

```c++
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int m = (l + r) / 2;
        
		int p = l, pn = nums[l];

		for (int i = l + 1; i <= r; i++) {
			if (nums[i] < pn) {
				swap(nums[i], nums[++p]);
			}
		}
		swap(nums[l], nums[p]);
		sort(nums, l, p - 1);
		sort(nums, p + 1, r);
    }
};

//左右靠近的
class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right){
        if(left > right) return;
        int p = left, q = right;
        int tmp = nums[left];
        while(p < q){
            while(p < q && nums[q] >= tmp) q--;
            nums[p] = nums[q];
            while(p < q && nums[p] <= tmp) p++;
            nums[q] = nums[p];
        }
        nums[q] = tmp;
        quickSort(nums, left, q-1);
        quickSort(nums, q+1, right);
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
```

```c++
class Solution {
public:
    vector<int> mg;
    vector<int> sortArray(vector<int>& nums) {
        mg = nums;
        sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void sort(vector<int>& nums, int l, int r) {
        int start = l;
        if (l == r) return;
        int m = (l + r) / 2;
        sort(nums, l, m);
        sort(nums, m + 1, r);

        int p1 = l, p2 = m+1;
        while (p1 <= m || p2 <= r) {
            if (p1 > m)
                nums[l++] = mg[p2++];
            else if (p2 > r)
                nums[l++] = mg[p1++];
            else if (mg[p1] >= mg[p2])
                nums[l++] = mg[p2++];
            else
                nums[l++] = mg[p1++];
        }

        for (int i = start; i <= r; i++) {
            mg[i] = nums[i];
        }
    }
};
```


---



