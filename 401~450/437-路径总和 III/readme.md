# 437. 路径总和 III

```c++
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题

自己随便写的方法，虽然避免的双递归，但是时间复杂度位O(n*logn)

```c++
class Solution {
public:
	vector<int> mc;
	int ans = 0;
	int pathSum(TreeNode* root, int sum) {
		if (!root) {
			return 0;
		}

		for (auto& t : mc) {
			t += root->val;
			if (t == sum)
				ans++;
		}
		mc.push_back(root->val);
		if (root->val == sum)
			ans++;
		
		pathSum(root->left,sum);
		pathSum(root->right, sum);

		mc.pop_back();
		for (auto& t : mc) {
			t -= root->val;
		}
		
		return ans;
	}
};
```

---

## 分析

主要是每次要遍历一边之前的值，用时太久。

所以第二种做法（作者：[a380922457](https://leetcode-cn.com/problems/path-sum-iii/solution/liang-chong-fang-fa-jian-dan-yi-dong-ban-ben-by-a3/)），采取了类似于数组的前n项和的思路，比如sum[4] == sum[1]，那么1到4之间的和肯定为0

对于树的话，采取DFS加回溯，每次访问到一个节点，把该节点加入到当前的pathSum中

然后判断是否存在一个之前的前n项和，其值等于pathSum与sum之差

如果有，就说明现在的前n项和，减去之前的前n项和，等于sum，那么也就是说，这两个点之间的路径和，就是sum

最后要注意的是，记得回溯，把路径和弹出去


```c++
class Solution {
    public int pathSum(TreeNode root, int sum) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        map.put(0, 1);
        return helper(root, map, sum, 0);
    }
    
    int helper(TreeNode root, HashMap<Integer, Integer> map, int sum, int pathSum){
        int res = 0;
        if(root == null) return 0;
        
        pathSum += root.val;
        res += map.getOrDefault(pathSum - sum, 0);
        map.put(pathSum, map.getOrDefault(pathSum, 0) + 1);
        res = helper(root.left, map, sum, pathSum) + helper(root.right, map, sum, pathSum) + res;
        map.put(pathSum, map.get(pathSum) - 1);
        return res;
    }
}



```