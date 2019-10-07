#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*
使用普通竖式得出的结果
执行用时 :16 ms, 在所有 C++ 提交中击败了42.55%的用户
内存消耗 :13.5 MB, 在所有 C++ 提交中击败了16.69%的用户
*/
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0")
			return num1;
		if (num2 == "0")
			return num2;


 		int len1 = num1.size();
		int len2 = num2.size();

		if (len2 > len1) {
			string t = num2;
			num2 = num1;
			num1 = t;

			int t2 = len2;
			len2 = len1;
			len1 = t2;
		}

		string ans = "0";


		

		for (int i = 0; i < len2; i++) {
			int carry = 0;
			string temp(len1, '0');

			int mul = num2[len2 - i - 1]-'0' ;
			for (int j = len1 -1; j >= 0; j--) {
				int mul2 = num1[j] - '0';
				int prod = mul * mul2 + carry;
				carry = prod / 10;
				temp[j] = prod % 10 +'0';
			}
			string tt(i, '0');
			if (carry != 0)
				ans = addstr(ans, to_string(carry) + temp + tt);
			else
				ans = addstr(ans, temp + tt);
		}

		return ans;


	}


	string addstr(string num1, string num2) {

		if (num1 == "0")
			return num2;
		if (num2 == "0")
			return num1;


		int len1 = num1.size();
		int len2 = num2.size();

		if (len2 > len1) {
			string t = num2;
			num2 = num1;
			num1 = t;

			int t2 = len2;
			len2 = len1;
			len1 = t2;
		}


		int carry = 0;
		string ans(len1, '0');


		for (int i = 0; i < len1; i++) {
			int add1 = num1[len1-i-1] - '0';
			int add2 = 0;
			if (i < len2) {
				add2 = num2[len2 - i -1] - '0';
			}
			int sum = add1 + add2 + carry;
			carry = sum / 10;
			ans[len1-i-1] = sum % 10 + '0';
		}

		if (carry == 0) {
			return ans;
		}
		else {
			return "1" + ans;
		}
		

	}
};

/*
除此之外，还可以使用优化竖式来加快算法：
两数相乘时，乘数某位与被乘数某位相乘，与产生结果的位置的规律来完成。具体规律如下：
乘数 num1 位数为 M，被乘数 num2 位数为 N, num1 x num2 结果 res 最大总位数为 M+N
num1[i] x num2[j] 的结果为 tmp(位数为两位，"0x","xy"的形式)，其第一位位于 res[i+j],第二位位于res[i+j+1]

class Solution {
	public String multiply(String num1, String num2) {
		if (num1.equals("0") || num2.equals("0")) {
			return "0";
		}
		int[] res = new int[num1.length() + num2.length()];
		for (int i = num1.length() - 1; i >= 0; i--) {
			int n1 = num1.charAt(i) - '0';
			for (int j = num2.length() - 1; j >= 0; j--) {
				int n2 = num2.charAt(j) - '0';
				int sum = (res[i + j + 1] + n1 * n2);
				res[i + j + 1] = sum % 10;
				res[i + j] += sum / 10;
			}
		}

		StringBuilder result = new StringBuilder();
		for (int i = 0; i < res.length; i++) {
			if (i == 0 && res[i] == 0) continue;
			result.append(res[i]);
		}
		return result.toString();
	}
}

作者：breezean
链接：https://leetcode-cn.com/problems/multiply-strings/solution/you-hua-ban-shu-shi-da-bai-994-by-breezean/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

int main()
{
	Solution s = Solution();
	vector<int> input = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	auto a = s.multiply( "99999", "99999");
	cout << a << endl;

	return 0;
}

