class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         int size = s.size();
//         int ans=0;
//         for(int i=0;i<size;i++){
//             vector<bool> visited(256);
            
//             for(int j=i;j<size;j++){
//                 if(visited[s[j]]==true) break;
                
//                 else{
//                     visited[s[j]]=true;
//                     ans = max(ans, j-i+1);
//                 }
//             }
            
//             visited[s[i]]=false;
//         }
//         return ans;
        
//         unordered_set<char> st;
        
//         int i=0, j=0, n=s.size();
//         int ans=0;
        
//         while(i<n && j<n){
//             if(st.find(s[j])==st.end()){
//                 st.insert(s[j++]);
//                 ans = max(ans, j-i);
                
//             }
//             else{
//                 st.erase(s[i++]);
//             }
//         }
//         return ans;
        
        vector<int> mp(256,-1);
        int left=0, right=0, len=0, maxlen=0;
        int n=s.size();
        while(right<n){
            if(mp[s[right]]!=-1){
                left=max(mp[s[right]]+1, left);
            }
            
            mp[s[right]]=right;
            len=max(len, right-left+1);
            right++;
        }
        return len;
        
        
    }
};