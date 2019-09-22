class Solution {
public:
	int myAtoi(string str) {
		int status = 0;
		int ans = 0;
		int sign = 1;// 表示 正负号
		for (auto c :str) {
			if (status == 1) {//仅读数字模式
				if (c >= '0' && c <= '9') {
					if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && c > '7') {
						if (sign ==1)
							return INT_MAX;
						else
							return INT_MIN; // >7 是因为防止复数比正数多一位造成的溢出
					}

					/*
					if (sign == 1 && ( ans > INT_MAX / 10 || ans == INT_MAX / 10 && c > '7')) {
						return INT_MAX;
					}
					if (sign == -1 && ( ans > INT_MAX / 10 || ans == INT_MAX / 10 && c > '7')) {
						return INT_MIN;  // >7 是因为防止复数比正数多一位造成的溢出
					}
					*/
					ans = ans*10 + (c - '0'); //！！！！！这里一定要加一个括号 否则会溢出
				}
				else {
					return sign * ans;
				}
				continue;
			}


			if (c == ' '){
				continue;
			}
			if (c == '-') {
				status = 1;  //status = 1表示开始读数字
				sign = -1;
				continue;
			}
			if (c == '+') {
				status = 1;
				continue;
			}
			if (c >= '0' && c <= '9') {
				status = 1;
				ans = c - '0';
				continue;
			}
			return 0;
		}
		return sign * ans;
	}
};