class Solution {
public:
    string longestPalindrome(string s) {
        
//         string ans="";
//         for(int i=0;i<s.size();i++){
//             for(int len=i;len<=s.size()-i;len++){
//                 string temp = s.substr(i,len);
//                 string temp2 = s.substr(i,len);
//                 reverse(temp2.begin(), temp2.end());
//                 if(temp==temp2){
//                     if(ans.length()<temp.length()){
//                         ans = temp;
//                     }
//                 }
                
//             }
//         }
//         cout<<ans<<endl;
//         return ans;
//         int m=s.size();
//         int n=m;
//         string text1=s;
//         string text2 = string(s.rbegin(),s.rend());
//         // vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
//         // return help(s, s2 , m, n,dp);
//         int dp[m+1][n+1];
//         for(int i=0;i<=m;i++) dp[i][0]=0;
//         for(int i=1;i<=n;i++) dp[0][i]=0;
        
//         // int res=0;
//         for(int i=1;i<=m;i++){
//             for(int j=1;j<=n;j++){
//                 if(text1[i-1]==text2[j-1]){
//                     dp[i][j] = 1+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = 0;
//                 }
                
//                 // res = max(res,dp[i][j]);
//             }
//         }
//         // cout<<res<<endl;
//         string s1="";
//         int i=m, j=n;
//         while(i>0 && j>0){
//             if(text1[i-1]==text2[j-1]){
//                 s1.push_back(text1[i-1]);
//                 i--;
//                 j--;
//             }
//             else{
//                 if(dp[i-1][j]>dp[i][j-1]){
//                     // s.push_back(str1[i-1]);
//                     i--;
//                 }
//                 else{
//                     // s.push_back(str2[j-1]);
//                     j--;
//                 }
//             }
//         }
//         return s1;
        int n = s.size();
        if (n == 0)
            return "";

        // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        bool dp[n][n];

        //Initialize with false

        memset(dp, 0, sizeof(dp));

        //Every Single character is palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        string ans = "";
        ans += s[0];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    //If it is of two character OR if its susbtring is palindrome.
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        //Then it will also a palindrome substring
                        dp[i][j] = true;

                        //Check for Longest Palindrome substring
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
        
        
        
        
        
        
        
        
    }
};