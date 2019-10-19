class Solution {//二分查找法求x发开方
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)    
            return x;
        int l = 0,r = x,mid;
        while(l <= r){
            mid = l + (r - l) /2;
            int s = x / mid; //不使用mid*mid来与x进行比较，防止int溢出
            if(x / s == s)
                return s; 
            if(s > mid && (x / (mid + 1)) < mid + 1) 
                return mid; 
            if(s > mid) l = mid + 1; //调整边界
            if(s < mid) r = mid - 1;
        }
        return 0;
    }
};
