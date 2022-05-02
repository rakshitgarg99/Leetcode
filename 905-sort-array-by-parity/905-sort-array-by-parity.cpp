class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j=nums.size()-1, k=0;
        int n=nums.size();
        
        while(k<j){
            if(nums[k]%2==0){
                k++;
                i++;
            }
            else if(nums[k]%2!=0){
                swap(nums[k], nums[j]);
                j--;
            }
            
        }
        return nums;
    }
};