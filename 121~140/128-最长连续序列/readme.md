# 128-最长连续序列

```c++
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 方法1：使用set，（只从一个连续数列中最小的数开始找（   if (!H.count(x - 1)） ）

主要思想时将查找的时间复杂度降为O(1),所以总体的时间复杂度即为O(n)

1. 使用`unordered_set<int> H(nums.begin(), nums.end());`将原数组转为set

2. 从最小的开始找起，一直试图向后查找，记录数量。

```c++
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> H(nums.begin(), nums.end());
		int ans = 0;
		for (int x : nums) {
			if (H.count(x - 1)) //如果不是最小的，直接跳过（应为最长的因该从最小的开始找起）
				continue;
			int a = x;
			int count = 1;
			while (H.count(a + 1)) { //一直往后找
				a ++;
				count ++;
			}
			ans = max(ans, count);
		}
		return ans;
	}
};

```

---

## 方法2：使用并查集（稀疏的并查集使用map实现）

将能构成连续序列的数字合并在一类。本题就是个分类问题。

用并查集记录H每个数字所属的类。

例如：[100, 4, 200, 1, 3, 2]

第一步，初始每个类都属于本身的类。H[100]=100,H[4]=4,H[200]=200,H[1]=1,H[3]=3,H[2]=2。

第二步，类之间建立关联。

对每个数字x，看x-1是否在已知的类中。

如果x-1是一个类，建立联系:H[x]=x-1。

H[100]=100,H[4]=3,H[200]=200,H[1]=1,H[3]=2,H[2]=1.

第三步，统计H中，每个类的数字个数。

并查集数据结构不复杂。

其最关键的功能是查找。给出一个数字x，找出其分类。

在递归查找并加上高度压缩。

本题用哈希表存储H更方便。

>参考了[这里](https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/liang-chong-jie-fa-by-jason-2-27/)

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> H;
        for(int i=0;i<2;++i){
            for(auto x:nums){
                if(i && H.count(x-1)){
                    H[x] = x-1; //第二轮，对于前一个数也存在的，将他的父节点设为前一个结点
                }
                find(H,x); //第一轮遍历，创建
            }    
        }
        
        unordered_map<int,int> C;
        for(auto p: H){
            int r = find(H,p.first);//获得p的类别（祖先的值）
            ++C[r]; //类别对应的C +1
        }
        int ans = 0;
        for(auto x: C){ //获得C中最大的元素
            ans = max(ans,x.second);
        }
        return ans;
    }
    
    int find(unordered_map<int,int>& H,int x){
        if(!H.count(x)) return H[x] = x;
        return H[x] == x ? x : H[x] = find(H,H[x]);
    }
};

```
