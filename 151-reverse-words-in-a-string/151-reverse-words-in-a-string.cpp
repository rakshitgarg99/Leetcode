class Solution {
public:
    string reverseWords(string str) {
        
//         stack<string> st;
//         string word="";
//         string ans="";
//         for(int i=0;i<s.size();i++){
//             while(i<s.size() and s[i]==' '){i++;}
            
//             while(i<s.size() and s[i]!=' '){
//                 word+=s[i];
//                 i++;
//             }
//             st.push(word);
//             word="";
            
//         }
        
//         while(!st.empty()){
//             string top=st.top();
//             st.pop();
//             ans = ans+" "+top;
//         }
        
//         int i=0;
//         while(i<ans.size() and ans[i]==' '){i++;}
//         return ans.substr(i,ans.size());
        
        
        if(str==""||str==" ") return "";
    string ans;
    int i=str.size()-1;
    
    while(i>=0){
        if(str[i]==' '){
            i--;
        }
        else{
            if(ans.size()>0){
                ans.push_back(' ');
            }
            
            int j=i;
            while(j>=0 and str[j]!=' '){
                j--;
            }
            ans.append(str.substr(j+1,i-j));
            i=j;
        }
    }
    return ans;
        
    }
};