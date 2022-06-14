class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string ans="1";
        n--;
        while(n--){
            
            string curr="";
            
            int temp=1;
            for(int i=0;i<ans.size();i++){
                if(ans[i]==ans[i+1] and i+1<ans.size()){
                    temp++;
                }
                else{
                    curr+=  to_string(temp)+ans[i];
                    temp=1;
                }
            }
            
            
            ans = curr;
            // cout<<ans<<endl;
        }
        
        return ans;
    }
};