# 面试题33. 二叉搜索树的后序遍历序列

```c++
面试题33. 二叉搜索树的后序遍历序列
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

 

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true
```

---

另一种方法，既不借助递归也不借助栈，思路来源于2015年大一时候学校C语言编程平台NOJ的一道题《火车站》，题目已经不记得了，大约就是判断任意一个数组是否可以由顺序数组[0,1,2,3,4] 任意方式进出栈生成，但是解决方法还有点印象。

```c++
class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		int len = postorder.size();
		vector<int> sorted = postorder;
		sort(sorted.begin(), sorted.end());
		for (int i = 0; i < len; i++) {
			postorder[i] = lower_bound(sorted.begin(), sorted.end(), postorder[i]) - sorted.begin();
		}
        //上面操作都是为了生成postorder中各元素的排名
        //（类似于R语言中的postorder = rank(postorder)）
        //如原数组是[1,3,2,6,5] ，经过rank以后就是 [0,2,1,3,4]
		
        
        vector<bool> visited(len, false);//表示rank后的postorder中的元素是否被访问
        
        
		for (int i = 0; i < len - 1; i++) {         
			visited[postorder[i]] = true;
            
            //重点关注逆序对，如果逆序对之间还有元素没有被访问，则说明有问题（细品）
			if (postorder[i + 1] < postorder[i]) { 
				int k = 0;
				for (int j = postorder[i + 1] + 1; j < postorder[i]; j++) {
					if (visited[j] == false) {
						return false;
					}
				}
			}
		}
		return true;
	}
};
```

---

常规方法：
作者：[zoememo](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/hou-xu-bian-li-di-gui-c-by-zoememo/)



```c++
class Solution {
    bool helper(vector<int>& post,int lo, int hi){
        if(lo >= hi) return true; //单节点或空节点返回true
        int root = post[hi]; //后序遍历序列最后的值为根节点的值
        int l = lo;
        while(l<hi && post[l]<root) 
            l++; //遍历左子树(值小于根)，左子树序列post[lo, l);
        int r = l;
        while(r<hi && post[r]>root)
            r++; //遍历右子树(值大于根)，右子树序列post[l, r);
        if(r != hi) return false;//若未将post[l, hi)遍历完，则非后序遍历序列 返回false
        return helper(post, lo, l-1) && helper(post, l, hi-1); //递归检查左右子树
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder,0,postorder.size()-1);
    }
};


```

