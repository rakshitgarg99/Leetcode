class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()) return false;
        map<char, int> mp1;
        map<char, int> mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]+=1;
            mp2[t[i]]+=1;
        }
        
        for(int i=0;i<s.size();i++){
            if(mp1[s[i]]!=mp2[s[i]]) return false;
        }
        
        return true;
        
        
    }
};