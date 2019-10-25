class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-- + n-- - 1; //从后往前合并可以减少讨论情况
        while (m >= 0 && n >= 0) {
            nums1[p--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        
        while (n >= 0) {
            nums1[p--] = nums2[n--];
        }
        //如果是m>0。则表示原始数组还没有合并完，此时就是原来的位置。不用改动
    }
};