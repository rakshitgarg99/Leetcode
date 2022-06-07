class Solution {
public:
    
    void solution(vector<int> nums, int i, int n, vector<vector<int>> &ans){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            solution(nums,i+1,n,ans);
            swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;        
        solution(nums, 0, nums.size(), ans);
        return ans;
    }
};