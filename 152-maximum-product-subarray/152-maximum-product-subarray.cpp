class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         if(nums.size()==1) return nums[0];
        
//         int mx=INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             int temp=nums[i];
//             for(int j=i+1;j<nums.size();j++){
//                 temp=temp*nums[j];
//                 mx = max(mx, temp);
//             }
//         }
//         int mx2 = *max_element(nums.begin(), nums.end());
//         return max(mx,mx2);
        
//         int res=nums[0], maxprod=nums[0], minprod=nums[0];
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]<0) swap(maxprod, minprod);
            
//             maxprod = max(maxprod*nums[i], nums[i]);
//             minprod = min(minprod*nums[i], nums[i]);
//             res = max(maxprod, res);
//         }
//         return res;
        
        
        
        int prod=1,maxprod=INT_MIN;
        for(int i=0;i<nums.size();i++){
            prod*=nums[i];
            maxprod=max(maxprod,prod);
            if(prod==0) prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            maxprod=max(maxprod,prod);
            if(prod==0) prod=1;
        }
        return maxprod;
    }
};