class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if(m==0) nums1=nums2;
        // else if(n==0){}
        // else{
        // int j=0;
        // for(int i=m;i<m+n;i++){
        //     nums1[i]=nums2[j];
        //     j++;
        //     // cout<<nums1[i]<<" ";
        // }
        // // for(auto x:nums1){cout<<x<<" ";}
        // sort(nums1.begin(), nums1.end());
        // }
        
        int i=m-1, j=n-1, k=m+n-1;
        
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }
        
        while(j>=0){
            nums1[k--]=nums2[j--];
        }
        
    }
};