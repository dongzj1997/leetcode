#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty()) return 0;
		stack<int> stack;
		int ans = 0;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); i++) {
			while (!stack.empty() && heights[i] < heights[stack.top()]) {  //一直出栈
				int top = stack.top();
				stack.pop();
				int t = stack.empty() ? i : i - stack.top() - 1;  //注意如果栈为空，则左边界可以理解为-1，右边界为i
				ans = max(ans, t * heights[top]);    //记住左边界一定要找最左边的值，如2，1，2 ，则1的左边界为-1，而不是0，，如为4，1，3，2，，则2的左边界为1
			}
			stack.push(i);
		}
		return ans;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> input = { 2,1,2};
	auto a = s.largestRectangleArea(input);

	//for (auto t : a) {
	//	for (auto tt : t) {
	//		cout << tt << " , ";
	//	}
	//	cout << endl;
	//}
	cout << a << endl;

	return 0;
}

