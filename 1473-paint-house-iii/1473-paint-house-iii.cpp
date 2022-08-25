class Solution {
public:
    
    int dp[101][21][101];
    
    int solve(int i, int l, int t, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        
        if(t>target) return INT_MAX/2;
        if(i==m){
            return t==target?0:INT_MAX/2;
        }
        
        
        if(dp[i][l][t]!=-1) return dp[i][l][t];
        int ans=INT_MAX/2;
        if(houses[i]==0){ //not colored
            
            for(int j=0;j<n;j++){
                ans = min(ans, cost[i][j]+solve(i+1,j+1,(l==j+1?t:t+1), houses, cost, m, n, target));
            }
        }
        else{
            ans = min(ans, solve(i+1,houses[i],(l==houses[i]?t:t+1), houses, cost, m, n, target));
        }
        
        return dp[i][l][t]=ans;
        
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,houses,cost,m,n,target);
        return ans==INT_MAX/2?-1:ans;
    }
};