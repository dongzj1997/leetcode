# 310. 最小高度树

```c++
对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。

格式

该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。

你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。

示例 1:

输入: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

输出: [1]
示例 2:

输入: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

输出: [3, 4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-height-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解题

基本思路：要求最小高度的根节点，其实就是求得最里面的那个节点，从叶子节点开始往根找，采用分层剥削的方法，每次去除最外层的叶子节点，最后剩下的一个或者两个节点就是我们所要的。

需要注意的点：

1. n为剩余的节点，循环条件是(n > 2)，但是删除节点时不能一个一个的删除 要一批一批的删除，这样才能保证剩下一个

2. 每次遍历edges需要的时间太长了，需要将原来的edges转为邻接链表或者set，方便查找

3. 每次遍历点查找度为1的点时间也太久了，采用事件驱动的方法，在删除一个节点时，查找对应的点的度数，判断是否要加入删除集中


```c++
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1) {
			return {0};
		}

		vector<int> del; //待删除的节点
		
		vector<unordered_set<int> > adj(n); //将原始的edges存储为一个邻接表
		for (auto edge : edges) {
			adj[edge[0]].insert(edge[1]);
			adj[edge[1]].insert(edge[0]);
		}

		for (int i = 0; i < n; i++) {
			if (adj[i].size() == 1) 
				del.push_back(i);
		}
		
		/*  //不能一个一个的删除 要一批一批的删除
		while (n > 2) {
			auto t = del[0]; //t 为要删除的节点号
			del.erase(del.begin());
			n--;
			int itm = *(adj[t].begin());
			adj[itm].erase(t);
			if (adj[itm].size() == 1)
				del.push_back(itm);
		}
		*/

		while (n > 2) {
			vector<int> temp = {};
			while (!del.empty()) {
				auto t = del[0]; //t 为要删除的节点号
				del.erase(del.begin());
				n--;
				int itm = *(adj[t].begin());
				adj[itm].erase(t);
				if (adj[itm].size() == 1)
					temp.push_back(itm);
			}
			del = temp;
		}

		return del;
	}
};
```

---

## 另一种解法

把每条边分配给其中一个端点，一共n-1条边，视为边从该端点出发，指向另一个端点。

剩余一个没有分配到边的节点作为该树的root，其他节点最终指向root。

寻找最深结点node[0],即最长路径的端点之一,node[1]为该节点深度。

变换树，使之前找到的节点成为root。

再次寻找最深节点node[0]。

找到node[0]到root的路径的中点，即为答案，返回。

```C++
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        int[][] gra = new int[n][];
        for(int[] edge : edges) {
            int a = edge[0], b = edge[1];
            if(gra[a] == null) gra[a] = edge;
            else gra[b] = edge;
        }
        int root = getRoot(gra);
        int[] node = getNode(gra, root);
        root = reverse(gra, root, node[0]);
        node = getNode(gra, root);
        
        //System.out.println(root + "/" + node[0] + ":" + node[1]);
        
        int len = node[1] / 2;
        int p = node[0];
        while(len-- != 0) p = getNext(gra, p); 
        res.add(p);
        if((node[1] & 1) == 1) res.add(getNext(gra, p));
        
        return res;
    }
    
    private int reverse(int[][] gra, int root, int p) {
        int ret = p;
        int[] pre = null;
        while(p != root) {
            int next = getNext(gra, p);
            int[] temp = gra[p];
            gra[p] = pre;
            pre = temp;
            p = next;
        }
        gra[root] = pre;
        return ret;
    }
    
    private int[] getNode(int[][] gra, int root) {
        int n = gra.length;
        int max = 0, node = 0;
        int[] h = new int[n];
        int[] stack = new int[n];
        int size = 0;
        for(int i = 0; i < n; i++) {
            int p = i, count = 0;
            while(p != root && h[p] == 0) {
                stack[size++] = p;
                p = getNext(gra, p);
            }
            while(size != 0) {
                int temp = stack[--size];
                h[temp] = h[p] + 1;
                if(h[temp] > max) {
                    max = h[temp];
                    node = temp;
                }
                p = temp;
            }
        }
        return new int[]{node, h[node]};
    }
    
    private int getRoot(int[][] gra) {
        int p = 0;
        while(gra[p] != null) p = getNext(gra, p);
        return p;
    }

    private int getNext(int[][] gra, int p) {
        int[] ret = gra[p];
        return ret[0] == p ? ret[1] : ret[0];
    }
    
}

作者：xie-ding-e-zhi-zhong
链接：https://leetcode-cn.com/problems/minimum-height-trees/solution/6ms-100-xun-zhao-lu-jing-zui-chang-de-liang-ge-jie/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```