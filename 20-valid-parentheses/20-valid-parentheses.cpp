class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        
//         for(auto x:str){

//             if(x=='(' or x=='{' or x=='['){
//                 s.push(x);
//             }
//             else{
//                 if(s.empty() or (x!=')' and s.top()=='(') or (x!=']' and s.top()=='[') or (x!='}' and s.top()=='{')){
//                     return false;
//                 }
//                 else{
//                     s.pop();
//                 }
                
//             }
//         }
        
        
//         if(s.empty()==true) return true;
//         return false;
        
        for(auto it: str) {
            if(it=='(' || it=='{' || it == '[') st.push(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
            }
        }
        return st.empty(); 
    }
};