class Solution {
public:
    
    string backspace(string s){
        stack<char> st;
        
        for(char c: s){
            if(c!='#'){
                st.push(c);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        s="";
        while(!st.empty()){
            char t=st.top();
            st.pop();
            s+=t;
        }
        
        return s;
        
        
    }
    
    bool backspaceCompare(string s, string t) {
        return backspace(s)==backspace(t);
    }
};