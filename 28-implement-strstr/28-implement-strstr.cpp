class Solution {
public:
    
    vector<int> prefix_sum(string s){
        
        int n=s.size();
        vector<int> pi(n,0);
        for(int i=1;i<n;i++){
            int j=pi[i-1];
            while(j>0 and s[i]!=s[j]){
                j=pi[j-1];
            }
            
            if(s[i]==s[j]){
                j++;
            }
            pi[i]=j;
        }
        
        return pi;
    }
    int strStr(string haystack, string needle) {
        
        
        vector<int> prefix = prefix_sum(needle);
        
        int n=haystack.size();
        int i=0,j=0,pos=-1;
        while(i<n){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                    j=prefix[j-1];
                }
                else{
                    i++;
                }
            }
            if(j==needle.size()){
                pos = i-needle.size();
                break;
            }
        }
        
        return pos;
    }
};