class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int ans=0;
        for(int i=0;i<size;i++){
            vector<bool> visited(256);
            
            for(int j=i;j<size;j++){
                if(visited[s[j]]==true) break;
                
                else{
                    visited[s[j]]=true;
                    ans = max(ans, j-i+1);
                }
            }
            
            visited[s[i]]=false;
        }
        return ans;
    }
};