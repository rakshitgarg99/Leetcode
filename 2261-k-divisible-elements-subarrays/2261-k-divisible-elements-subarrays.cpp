class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;
        
        for(int i=0;i<nums.size();i++){
            vector<int> temp; int kcnt=0;
            for(int j=i;j<nums.size();j++){
                if(kcnt<=k){
                    if(nums[j]%p==0){
                        kcnt++;
                    }
                    if(kcnt<=k){
                    temp.push_back(nums[j]);
                    st.insert(temp);
                    }
                    
                }
            }
        }
        
        return st.size();
    }
};