class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int cursum=0,maxsum=0;
        
        set<int> s;
        int start, end;
        
        while(end<nums.size()){
            if(s.find(nums[end])==s.end()){
                cursum+=nums[end];
                s.insert(nums[end]);
                maxsum=max(maxsum, cursum);
                end++;
            }
            else{
                s.erase(nums[start]);
                cursum-=nums[start];
                start++;
            }
        }
        
        return maxsum;
    }
};