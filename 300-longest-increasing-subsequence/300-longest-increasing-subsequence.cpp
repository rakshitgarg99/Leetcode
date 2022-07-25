class Solution {
public:
    
    int solve(vector<int>& nums, int idx, int prev_idx, vector<vector<int>> &dp){
        if(idx==nums.size()) return 0;
        
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        
        
        int take{};
        int donttake = solve(nums, idx+1,prev_idx,dp);
        if(prev_idx==-1 or nums[idx]>nums[prev_idx]){
            take = 1+solve(nums, idx+1,idx,dp);
        }
        
        return dp[idx][prev_idx+1] = max(take, donttake);
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(nums, 0, -1, dp);
        
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        // for(int i=0;i<)
    }
};