class Solution {
public:
    
//     int solve(string s, string t, int n, int m, vector<vector<int>> &dp){
//         if(m==0) return 1;
//         if(n==0) return 0;
        
//         if(dp[n][m]!=-1) return dp[n][m];
        
//         if(s[n-1]==t[m-1]){
//             return dp[n][m]= solve(s,t,n-1,m-1,dp)+solve(s,t,n-1,m,dp);
//         }
//         else{
//             return dp[n][m]=solve(s,t,n-1,m,dp);
//         }
//     }
    int numDistinct(string s, string t) {
//         int n=s.size();
//         int m=t.size();
//         // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        
//         // return solve(s,t,n,m,dp);
//         vector<vector<double>> dp(n+1, vector<double>(m+1,0));
//         for(int i=0;i<=n;i++){
//             dp[i][0]=1;
//         }
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;i<=m;j++){
//                 if(s[i-1]==t[j-1]){
//                     dp[i][j]= dp[i-1][j-1] + dp[i-1][j];
//                 }
//                 else{
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
//         return (int)dp[n][m];
        int m = t.length(), n = s.length();
        vector<vector<double>> dp(m + 1, vector<double> (n + 1, 0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
        return (int)dp[m][n];
    }
};