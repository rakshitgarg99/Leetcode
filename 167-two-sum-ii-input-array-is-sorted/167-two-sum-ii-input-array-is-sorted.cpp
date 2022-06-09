class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> mp;
        
        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i];
            if(mp.find(temp)!=mp.end()){
                ans.push_back(mp[temp]);
                ans.push_back(i+1);
            }
            else{
                mp[nums[i]]=i+1;
            }
        }
        return ans;
    }
};