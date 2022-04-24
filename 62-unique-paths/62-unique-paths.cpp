class Solution {
public:
    /*
    long int solve(int m, int n, vector<vector<int>> &dp){
        if(m<0 || n<0) return 0;
        if(m==0 and n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int x = solve(m-1, n,dp);
        int y = solve(m, n-1,dp);
        return dp[m][n]=x+y;
    }
    */
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
        // return solve(m-1,n-1, dp);
        
        int N = n + m - 2;
        int r = m - 1;
        double res = 1;
        for (int i = 1; i <= r; i++)
            res = res * (N-r+i)/i;

        return (int)res;

    }
};