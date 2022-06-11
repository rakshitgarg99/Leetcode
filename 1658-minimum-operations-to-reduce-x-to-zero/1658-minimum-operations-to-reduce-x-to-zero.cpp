class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans;
        int sum=0;
        
        for(auto x:nums){
            sum+=x;
        }
        
        sum-=x; // sum to find
        if(sum==0) return nums.size();
        
        
        int currsum=0,i=0,j=0,len=0;
        for(int j=0;j<nums.size();j++){
            currsum+=nums[j];
            
            while(i<nums.size() && currsum>sum){
                currsum-=nums[i++];
            }
            
            if(currsum==sum){
                len=max(len, j-i+1);
            }
        }
        
        if(!len) return -1;
        return nums.size()-len;
    }
};