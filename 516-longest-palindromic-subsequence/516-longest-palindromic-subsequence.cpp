#include <bits/stdc++.h>
class Solution {
public:
    
    int help(string a, string b, int m, int n, vector<vector<int>> &dp){
        if(m==0||n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        if(a[m-1]==b[n-1]){
            return dp[m][n] = 1+help(a, b, m-1, n-1,dp);
        }
        else{
            return dp[m][n] = max(help(a,b,m-1,n,dp), help(a,b,m,n-1,dp));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        
        int m=s.size();
        int n=m;
        string text1=s;
        string text2 = string(s.rbegin(),s.rend());
        // vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
        // return help(s, s2 , m, n,dp);
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++) dp[0][i]=0;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};