class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=ceil(nums.size()/2);
        
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]+=1;
            if(mp[x]>n) return x;
        }
        
        return 0;
    }
    
};