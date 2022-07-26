class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        
        int n=nums.size();
        vector<int> dp(n+1,1), hash(n);
        int lastidx=0, maxi=1;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j]==0 and 1+dp[j]>dp[i]){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            
            if(dp[i]>maxi){
                maxi = dp[i];
                lastidx = i;
            }
        }
        
        
        vector<int> temp;
        temp.push_back(nums[lastidx]);
        
        while(hash[lastidx]!=lastidx){
            lastidx = hash[lastidx];
            temp.push_back(nums[lastidx]);
        }
        
        reverse(temp.begin(), temp.end());
        return temp;
    }
};