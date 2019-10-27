#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stack>

using namespace std;
/*
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :9 MB, 在所有 cpp 提交中击败了81.35%的用户
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode *> S;
		while (root != nullptr) { //将整个最左端全部push进去
			S.push(root);
			root = root->left;
		}

		while (!S.empty()) {
			TreeNode* t = S.top();
			S.pop();
			ans.push_back(t->val);
			
			t = t->right;//将刚刚pop掉的节点右子树去除
			while (t != nullptr) { //左侧入栈
				S.push(t);
				t = t->left;
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
	auto a = s.inorderTraversal(8);

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