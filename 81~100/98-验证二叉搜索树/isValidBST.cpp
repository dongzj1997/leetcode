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
	bool isValidBST(TreeNode* root) {
		return dfs(root, LLONG_MIN, LLONG_MAX);
	}

	bool dfs(TreeNode* root,long long lower, long long upper) { //定义上下边界
		if (root == NULL)
			return true;
		long long v = root->val;
		if (lower != LLONG_MIN && v <= lower)
			return false;
		if (upper != LLONG_MAX && v >= upper)
			return false;
		return dfs(root->left, lower ,v) && dfs(root->right,v, upper);
		//如果检查左子树，则值的上界变小，下界还是原来的下界，同理，检查右子树时，上界不变，最小值（下界）变大
	}
};
int main()
{

	Solution s = Solution();

	//vector<vector<int>> input = { {0},{0},{1},{0} };
	//vector<string> input = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<int> input = { 2,5,6,0,0,1,2 };
	auto a = s.isValidBST("aabcc","dbbca","aadbbbaccc");

	//for (auto line : a) {
	//	for (auto c : line) {
	//		cout << c <<"" ;
	//	}
	//	cout << endl;
	//}

	//for (auto line : a) {
	//	
	//	cout <<line<< " , ";
	//}

	cout << a << endl;

	return 0;
}