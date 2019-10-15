class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int k = m - 1;  
        long long ans = 1;  //防止计算中出现溢出
        for (int i = 1; i <= k; i++)
            ans = ans * (N - k + i) / i;
        return (int)ans;
    }
};
/*
可以看作是一共有 n + m - 2个步骤，从中选出n-1个步骤采用向下走，结果即为组合数C_(n + m - 2)^(n-1)
*/