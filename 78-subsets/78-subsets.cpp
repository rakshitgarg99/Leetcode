class Solution {
public:
    
    void solution(vector<int> &nums, int i, int n, vector<vector<int>> &ans, vector<int> temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        
        solution(nums, i+1,n,ans,temp);
        temp.push_back(nums[i]);
        solution(nums, i+1,n,ans,temp);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        solution(nums,0,n,ans,temp);
        
        return ans;
    }
};