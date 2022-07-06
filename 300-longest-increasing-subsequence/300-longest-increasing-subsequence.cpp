class Solution {
public:
    
    int solve(vector<int>&nums,int i, int prev){
        if(i>=nums.size())return 0;
        
        int dontTake = solve(nums, i + 1, prev);
        int take=0;
        if(nums[i]>prev) take=1+solve(nums,i+1,nums[i]);
        
        return max(take,dontTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // return solve(nums,0,INT_MIN);
        
        vector<int> lis(n,1);
        int mx=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] and lis[i]<=lis[j]){
                    lis[i]+=1;
                }
                mx=max(mx,lis[i]);
            }
        }
        return mx;
    }
};