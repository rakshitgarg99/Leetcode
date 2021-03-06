class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        if(nums.empty()) return ans;
        
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                int temp=target-(nums[i]+nums[j]);
                
                int front=j+1;
                int back=n-1;
                
                while(front<back){
                    int sum2= nums[front]+nums[back];
                    
                    if(sum2<temp) front++;
                    else if(sum2>temp) back--;
                    else{
                        
                        vector<int> quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[back];
                        
                        ans.push_back(quad);
                        
                        
                        while(front<back && nums[front]==quad[2]) front++;
                        while(front<back and nums[back]==quad[3]) back--;
                    }
                    
                }
                
                while(j+1<n and nums[j]==nums[j+1]) j++;
            }
            while(i+1<n and nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};