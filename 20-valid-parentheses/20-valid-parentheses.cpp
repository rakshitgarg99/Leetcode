class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        
        for(auto x:str){

            if(x=='(' or x=='{' or x=='['){
                s.push(x);
            }
            else{
                if(s.empty() or (x!=')' and s.top()=='(') or (x!=']' and s.top()=='[') or (x!='}' and s.top()=='{')){
                    return false;
                }
                else{
                    s.pop();
                }
                
            }
        }
        
        
        if(s.empty()==true) return true;
        return false;
    }
};