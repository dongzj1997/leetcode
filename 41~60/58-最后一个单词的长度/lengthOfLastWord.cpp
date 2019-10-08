class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int ans =0;
        for( int i = len -1;i>=0;i--){
            if(s[i] != ' '){
                for(; i>=0;i-- ){
                    if(s[i] != ' '){
                        ans++;
                    }else{
                        break;
                    }
                }
                break;
                
            }
        }
        return ans;
        
    }
};