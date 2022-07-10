class Solution {
public:
    
    int solve(vector<int> cost, int n, vector<int> &dp){
        if(n<0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        int op1= cost[n]+solve(cost,n-1,dp);
        int op2=0;
        if(n-1>=0) op2= cost[n-1]+solve(cost, n-2,dp);
        
        return dp[n]=min(op1,op2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return solve(cost, n-1,dp);
    }
};