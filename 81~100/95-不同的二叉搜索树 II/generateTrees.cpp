#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) {
			return vector<TreeNode*>{};
		}

		return dfs(1, n);
	}

	vector<TreeNode*> dfs(int start, int end) {
		vector<TreeNode*> ans;
		if (end < start) {
			ans.push_back(nullptr);
			return ans;
		}
		for (int i = start; i <= end; i++) {
			vector<TreeNode*> left = dfs(start, i - 1); //这里有一个重复创建的问题，严重影响效率，如果将结果存起来可以节约不少时间
			vector<TreeNode*> right = dfs(i + 1, end);  //同上
			for (auto l : left) {
				for (auto r : right) {
					TreeNode* root = new TreeNode(i);   //以第i个节点为根，对左右两边的 数排列组合
					root->left = l;           //总个数为卡塔兰数
					root->right = r;
					ans.push_back(root);
				}
			}
		}
		return ans;
	}
};


int main()
{

	Solution s = Solution();

	//vector<vector<int>> input = { {0},{0},{1},{0} };
	//vector<string> input = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<int> input = { 2,5,6,0,0,1,2 };
	auto a = s.generateTrees(3);

	//for (auto line : a) {
	//	for (auto c : line) {
	//		cout << c <<"" ;
	//	}
	//	cout << endl;
	//}

	for (auto line : a) {
		
		cout <<line<< " , ";
	}

	//cout << a << endl;

	return 0;
}