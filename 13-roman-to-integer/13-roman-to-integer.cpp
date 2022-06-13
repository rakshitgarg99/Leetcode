class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int n = s.size()-1;
        int ans=0, cur=0, prev=0;
        while(n>=0){
            cur = m[s[n]];
            if(cur<prev){
                ans -= cur;
            }else{
                ans += cur;
            }
            prev=cur;
            n--;
        }
        
        return ans;
    }
};