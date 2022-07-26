class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,1), count(n+1,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] and dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    count[i] = count[prev];
                }
                else if(nums[i]>nums[prev] and dp[i]==1+dp[prev]){
                    count[i] += count[prev];
                }
            }
            
            maxi = max(maxi, dp[i]);
        }
        
        int nos=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) nos+=count[i];
        }
        
        return nos;
    }
};