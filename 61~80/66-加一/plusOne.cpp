#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
/*
class Solution {//常规方法
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits[0] == 0) {
			return { 1 };
		}
		int carry = 1;
		int t = 0;
		int len = digits.size();
		for (int i = len - 1; i >= 0 && carry; i--) {
			t = carry + digits[i];
			digits[i] = t % 10;
			carry = t / 10;
		}
		if (carry) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

*/
class Solution { //另一种比较快速的方法，直接检测第一次出现不是9的位置，如果没有，则全部置为0然后第一位插入1
public:
	vector<int> plusOne(vector<int>& digits) {
		for (int i = (int)digits.size() - 1; i >= 0; i--) {
			if (digits[i] == 9) {
				digits[i] = 0;
			}
			else {
				digits[i]++;
				break;
			}
		}
		if (digits[0] == 0) {
			digits.push_back(0);
			digits[0] = 1;
		}
		return digits;
	}
};


int main()
{

	Solution s = Solution();
	//vector<vector<int>> input = { {0},{0},{1},{0} };
	vector<int> input = {0};
	auto a = s.plusOne(input);

	/*for (auto line : a) {
		for (auto c : line) {
			cout << c << " , ";
		}
		cout << endl;
	}*/

	for (auto line : a) {
		
		cout <<line<< " , ";
	}

	//cout << a << endl;

	return 0;
}