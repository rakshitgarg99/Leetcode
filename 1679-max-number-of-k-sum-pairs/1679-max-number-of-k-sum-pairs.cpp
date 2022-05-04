class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> mp;
        int count=0;
        for(auto x:nums){
            int target=k-x;
            
            if(mp.find(target)!=mp.end()){
                if(mp[target]==1){
                    mp.erase(target);
                }
                else{
                    mp[target]=mp[target]-1;
                }
                count++;
            }
            else{
                mp[x]++;
            }
        }
        return count;
    }
};