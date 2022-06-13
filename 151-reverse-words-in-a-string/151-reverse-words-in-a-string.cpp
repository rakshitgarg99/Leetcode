class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        string word="";
        string ans="";
        for(int i=0;i<s.size();i++){
            while(i<s.size() and s[i]==' '){i++;}
            
            while(i<s.size() and s[i]!=' '){
                word+=s[i];
                i++;
            }
            st.push(word);
            word="";
            
        }
        
        while(!st.empty()){
            string top=st.top();
            st.pop();
            ans = ans+" "+top;
        }
        
        int i=0;
        while(i<ans.size() and ans[i]==' '){i++;}
        return ans.substr(i,ans.size());
    }
};