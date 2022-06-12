class Solution {
public:
    int ans;
    
    void solve(vector<int> &c, int i, vector<int>&bags){
        int k=bags.size();
        
        if(i==c.size()){
            int mx=INT_MIN;
            
            for(int x=0;x<k;x++){
                mx = max(mx,bags[x]);
            }
            
            ans = min(mx,ans);
            return;
        }
        
        for(int x=0;x<k;x++){
            bags[x]+=c[i];
            solve(c,i+1,bags);
            bags[x]-=c[i];
        }
    }
    
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k,0);
        ans=INT_MAX;
        solve(cookies,0,v);
        return ans;
    }
};