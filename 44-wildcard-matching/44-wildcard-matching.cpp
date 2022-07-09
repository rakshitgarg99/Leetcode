class Solution {
public:
    
    
    bool solve(string s, string p, int n, int m, vector<vector<int>> &dp){
        //Base case
        if(n==0 and m==0) return true;
        if(n==0 and m>0) return false;
        if(n>0 and m==0){
            for(int i=1;i<=n;i++){
                if(s[i-1]!='*') return false;
            }
            return true;
        }
        
        //recurrence
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(s[n-1]==p[m-1] or s[n-1]=='?'){
            return dp[n][m]=solve(s,p,n-1,m-1,dp);
        }
        if(s[n-1]=='*'){
            return dp[n][m]=solve(s,p,n-1,m,dp) or solve(s,p,n,m-1,dp);
        }
        return dp[n][m]=false;
    }
    
    bool isMatch(string s, string p) {
        // int n=s.size(), m=p.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        // return solve(p,s,m,n,dp);
        
        
        int n=p.size(), m=s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++){
            dp[0][j]=false;
        }
        for(int i=1;i<=n;i++){
            bool fl=true;
            for(int j=1;j<=i;j++){
                if(p[j-1]!='*'){
                    fl=false;
                    break;
                }
            }
            dp[i][0]=fl;
        }
        
        for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {

      if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];

      else {
        if (p[i - 1] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

        else dp[i][j] = false;
      }
    }
  }

  return dp[n][m];
    }
};