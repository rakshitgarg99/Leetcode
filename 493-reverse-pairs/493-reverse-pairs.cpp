class Solution {
public:
    
    int merge(vector<int>& nums,vector<int>& temp, int s, int mid, int e){
        int i=s, k=s, j=mid;
        int count=0;
        
        while(i<=mid-1 && j<=e){
            if((long)nums[i] > (long)2 * nums[j]){
                count+= mid-i;
                j++;
            }
            else{i++;}
        }
        
        i=s, k=s, j=mid;
        
        while(i<=mid-1 && j<=e){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }
        
        while(i<=mid-1){
            temp[k++]=nums[i++];
        }
        while(j<=e){
            temp[k++]=nums[j++];
        }
        
        for(i=s;i<=e;i++){
            nums[i]=temp[i];
        }
        return count;
        
    }
    
    int mergesort(vector<int>& nums,vector<int>& temp, int s, int e){
        int count=0,mid=0;
        if(s<e){
            mid=(s+e)/2;
            count+=mergesort(nums,temp, s, mid);
            count+=mergesort(nums,temp, mid+1, e);
            
            count+=merge(nums,temp, s, mid+1, e);
        }
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergesort(nums, temp, 0, nums.size()-1);
    }
};