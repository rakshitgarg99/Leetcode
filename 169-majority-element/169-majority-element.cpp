class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=ceil(nums.size()/2);
        
//         unordered_map<int,int> mp;
//         for(auto x:nums){
//             mp[x]+=1;
//             if(mp[x]>n) return x;
//         }
        
//         return 0;
        
        int count=0, curr=nums[0];
        for(int i=0;i<nums.size();i++){
            if(count==0) curr=nums[i];
            if(curr==nums[i]){
                count++;
            }
            else{
                count--;
            }
            
        }
        return curr;
    }
    
};