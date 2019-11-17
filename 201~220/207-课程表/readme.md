# 207. 课程表

```c++
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

示例 1:

输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:

输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
说明:

输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
提示:

这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 方法1 拓扑排序法（使用入度表）

算法思想是统计每个节点的入度，先根据输入生成一个入度表，然后执行如下步骤：

1. 先将入度表中入度为0 的节点统计出来，加入循环队列中

2. 对每个入度为0的节点，将他指向的节点入度减一

3. 减一以后判断入度，如果为0，则加入循环队列

4. 不断循环，直到循环队元素为0

5. 统计所有出现过的入度为0的节点，看是否等于总结点数

```c++
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		if (numCourses <= 0)   // numCourses 为课程的数量
			return false;
		int len = prerequisites.size();   //关系数量
		if (len == 0) 
			return true;
		vector<int> inDegree(numCourses);  //建立一个每个点的入度表

		for (int i=0;i<len;i++)
			inDegree[prerequisites[i][0]]++;   //各个节点的入度初始化

		queue<int> q;
		vector<vector<int>> mp(numCourses);  //为了方便查找，建一个map，存储的是每个点(key= int)可以引出的点(val = vector<int>)


		for (auto& x : prerequisites) {  //遍历一次关系

			mp[x[1]].push_back(x[0]);
		}


		for (int i = 0; i < numCourses; i++)// 首先加入入度为 0 的结点
		{
			if (inDegree[i] == 0)
				q.push(i);
		}

		vector<int> res;// 拓扑排序的结果
		while (!q.empty())
		{
			int num = q.front();
			q.pop();
			res.push_back(num);
			// 把邻边全部遍历一下
			for (int k = 0; k < mp[num].size(); k++) {
				inDegree[mp[num][k]]--;
				if (inDegree[mp[num][k]] == 0)
					q.push(mp[num][k]);
			}
		}
		return res.size() == numCourses;
	}
};

```

---

## 解法2 使用DFS检测是否有环

首先，借助一个标志列表 flags，用于判断每个节点i（课程）的状态：

未被 DFS 访问：flags[i] == 0；（dfs遇到时执行下一层的搜索）

已被其他节点启动的DFS访问：flags[i]  == -1；(dfs遇到时无需重复搜索，返回 True，表示该节点无环。)

已被当前节点启动的DFS访问：flags[i]  == 1。 （dfs遇到时 直接返回fasle）

```python
        def dfs(i, adjacency, flags):
            if flags[i] == -1: return True
            if flags[i] == 1: return False
            flags[i] = 1
            for j in adjacency[i]:
                if not dfs(j, adjacency, flags): return False
            flags[i] = -1
            return True

```
