class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        
        for(int j=0;j<grid[0].size();j++){
            dp[grid.size()-1][j] = grid[grid.size()-1][j]; 
        }
        
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int ans=INT_MAX;
                for(int k=0;k<m;k++){
                    ans = min(ans, dp[i+1][k]+ moveCost[grid[i][j]][k]);
                }
                
                dp[i][j] = ans+grid[i][j];
            }
        }
        
        int ans = *min_element(dp[0].begin(), dp[0].end());
        return ans;
    }
};