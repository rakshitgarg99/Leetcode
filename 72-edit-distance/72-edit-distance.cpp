class Solution {
public:
    
    int solve(string word1, string word2, int m, int n, vector<vector<int>> &dp){
        // if(m==0||n==0) return 0;
        if(m==0) return n;
        if(n==0) return m;
        if(dp[m][n]!=-1) return dp[m][n];
        if(word1[m-1]==word2[n-1]){
            return dp[m][n]=solve(word1, word2, m-1,n-1,dp);
        }
        else{
            int i=1+solve(word1,word2,m-1,n,dp);
            int d=1+solve(word1,word2,m,n-1,dp);
            int r=1+solve(word1,word2,m-1,n-1,dp);
            return dp[m][n]=min(i,min(d,r));
        }
    }
    
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        int ans=solve(word1, word2, m, n, dp);
        return ans;
    }
};