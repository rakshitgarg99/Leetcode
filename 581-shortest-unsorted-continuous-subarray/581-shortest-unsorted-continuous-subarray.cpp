class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp=nums;
        sort(temp.begin(), temp.end());
        int count=0, t1, t2;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=temp[i]){ t1=i; break;}
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]!=temp[i]){ 
                count = (i+1)-t1;
                break;
            }
        }
        return count;
    }
};