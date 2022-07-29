class Solution {
public:
    int maxCoins(vector<int>& cuts) {
        
        int c=cuts.size();
        cuts.push_back(1);
        cuts.insert(cuts.begin(), 1);
        
        vector<vector<int>> dp(c+2, vector<int>(c+2,0));
        
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j) continue;
                int mini = INT_MIN;
                for(int k=i;k<=j;k++){
                    int temp = cuts[j+1]*cuts[i-1]*cuts[k] + dp[i][k-1]
                        + dp[k+1][j];

                    mini = max(mini, temp);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][c];
        
    }
};