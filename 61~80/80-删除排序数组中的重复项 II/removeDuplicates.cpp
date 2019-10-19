class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int i = 0;
        int count = 1;
        for (int j = 1; j < nums.size(); j++){
            if (nums[i] != nums[j]){
                nums[++ i] = nums[j];
                count = 1;
            }else if (count >= 2){
                continue;
            }else{
                nums[++ i] = nums[j];
                count ++;
            }
        }
        return i + 1;
    }
};