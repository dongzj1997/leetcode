# 332，重新安排行程   

```c++
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 出发。

说明:

如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
所有的机场都用三个大写字母表示（机场代码）。
假定所有机票至少存在一种合理的行程。
示例 1:

输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]
示例 2:

输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reconstruct-itinerary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

## 解析

先将没有规律的一维数据构造为map形式的邻接表，便于查找。

然后使用dfs 的方法，不断向深递归，直到将所有的tickets耗尽，返回true

注意回溯时使用下面的代码来保证搜索空间的唯一性
```c++
ans.push_back(s); //添加路径答案
t.erase(t.begin() + i); // 删除已使用的票据
n--; //总票据数-1

ans.pop_back();
t.insert(t.begin() + i, s);
n++;
```

总体代码：

```c++
class Solution {
public:
	unordered_map< string,vector<string> > table; //节点的邻接表
	vector<string> ans;
	int n = 0;

	vector<string> findItinerary(vector<vector<string>>& tickets) {

		n = tickets.size();
		//构造邻接表，排序
		for (auto pair : tickets) {
			if (table.count(pair[0]) == 0) {

				vector<string> t = { pair[1] };
				table[pair[0]] = t;
			}
			else {
				vector<string>& t = table[pair[0]];
				auto it = t.begin();
				while (it != t.end() && *it < pair[1]) {
					it++;
				}
				t.insert(it, pair[1]);
			}
		}

		//dfs搜索
		ans.push_back("JFK");
		helper("JFK");
		return ans;
	}

	bool helper(string from) {
		if (n == 0) {
			return true;
		}
		vector<string>& t = table[from];

		for (int i = 0; i < t.size(); i++) {
			auto s = t[i];
			ans.push_back(s);
			t.erase(t.begin() + i);
			n--;

			if (helper(s)) {
				return true;
			}
			else {
				ans.pop_back();
				t.insert(t.begin() + i, s);
				n++;
			}

		}

		return false;
	}
};
```

---

又是一次AC，为什么这么强！

---

## 另一种解法：eulerian path

>这个例子可以看出，我们别无选择必须先从 JFK 到 NRT 再回 JFK，最后到达 KUL 作为终点。如果我们按照字典顺序先到 KUL，就进入了 “死路”。但是上一个例子我们提到了，优先访问字典顺序小的顶点，那么我们第一次肯定是先到 KUL，这就走不通了，那怎么解决呢？当我们采用 DFS 方式遍历图时，需要将访问到的节点逆序插入到结果集。因此第一个访问到的节点将出现在结果集最后面，而我们是以顺序的方式来查看结果。如果第一个访问的节点是 “孤岛节点”，他会出现在结果集的最后。当我们顺序读取结果集时，这种 “孤岛节点” 是最后遇到的，是图遍历的终点，这样就没有问题了。

![img](./1.png)

>我们在图 3 绘制了算法执行过程，黑色实线表示图的边；红色实实线表示递归调用；绿色虚线表示递归调用返回；数字代表执行顺序；文字表示执行的操作，结果集的数字表示在第几步操作加入的。我们从 JFK 出发，沿着边到达 KUL（因为 KUL 字典顺序比 NRT 小），然后 KUL 没有临接点，将它放入结果集(2)，然后从 KUL 返回到达 JFK，注意这个是通过调用栈返回而不是沿着边返回。然后从 JFK 出发沿着边到达NRT，因为 NRT 到 JFK 有返回边，沿着边再回到 JFK。此时 JFK 的两个临接点都访问过了，我们将 JFK 加入结果集(6)。然后我们从 JFK 返回到 NRT，这是从调用栈返回。然后 NRT 的临接点都访问过了，我们将 NRT 加入结果集(8)，然后退栈回到 JFK。JFK 的所有临接点都访问过了，将 JFK 加入结果集(10)，然后退栈，整个流程结束。

>在实现方面，我们使用 Map<String, List<String>> 存储图，Key 为顶点，List<String> 为临接点。为了避免存在环路导致节点重复访问，我们每访问过一条边就把它标记为访问过，或者直接将访问过的边删除。为了实现按照字典顺序访问，我们把每个顶点的临接点按照字典顺序排序。这里，我们直接将访问过的边删除，然后每次都取临接点的第一个即可满足字典顺序访问。

```java
import java.util.*;
class Solution {
    public List findItinerary(List> tickets) {
        // 因为逆序插入，所以用链表
        List ans = new LinkedList<>();
        if (tickets == null || tickets.size() == 0)
            return ans;
        Map> graph = new HashMap<>();
        for (List pair : tickets) {
            // 因为涉及删除操作，我们用链表
            List nbr = graph.computeIfAbsent(pair.get(0), k -> new LinkedList<>());
            nbr.add(pair.get(1));
        }
        // 按目的顶点排序
        graph.values().forEach(x -> x.sort(String::compareTo));
        visit(graph, "JFK", ans);
        return ans;
    }
    // DFS方式遍历图，当走到不能走为止，再将节点加入到答案
    private void visit(Map> graph, String src, List ans) {
        List nbr = graph.get(src);
        while (nbr != null && nbr.size() > 0) {
            String dest = nbr.remove(0);
            visit(graph, dest, ans);
        }
        // 将src的所有可能性走完，然后将src逆序插入到最终结果中
        ans.add(0, src); // 逆序插入
    }
}

```

>转自[pwrliang](https://leetcode-cn.com/problems/reconstruct-itinerary/solution/javadfsjie-fa-by-pwrliang/)  
来源：力扣（LeetCode）
