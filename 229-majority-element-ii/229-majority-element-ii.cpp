class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int cnt1=0, cnt2=0, cnd1=0, cnd2=0;
        for(auto x:nums){
            if(cnd1==x) cnt1++;
            else if(cnd2==x) cnt2++;
            else if(cnt1==0) {cnd1=x; cnt1=1;}
            else if(cnt2==0) {cnd2=x; cnt2=1;}
            else {cnt1--;cnt2--;}
        }
        
        vector<int> ans;
        int temp1=0, temp2=0;
        for(auto x:nums){
            if(x==cnd1) temp1++;
            else if(x==cnd2) temp2++;
        }
        
        if(temp1>nums.size()/3) ans.push_back(cnd1);
        if(temp2>nums.size()/3) ans.push_back(cnd2);
        // cout<<cnd1<<cnd2<<" ";
        return ans;
    }
};