class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
//         sort(nums.begin(), nums.end());
        
//         int max_len=0, temp=0;
//         for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]==nums[i+1]){}
//             else if(nums[i]==nums[i+1]-1){
//                 // cout<<nums[i];
//                 temp++;
//             }else{
//                 max_len=max(max_len, temp);
//                 temp=0;
                
//             }
//         }
//         max_len=max(max_len, temp);
//         return max_len+1;
        
        set<int> s(nums.begin(), nums.end());
        int maxlen=0;
        for(auto num:s){
            if(!s.count(num-1)){
                int currstreak=1;
                int currnum=num;
                
                while(s.count(currnum+1)){
                    currstreak++;
                    currnum++;
                }
                
                maxlen=max(maxlen, currstreak);
            }
        }
        return maxlen;
    }
};