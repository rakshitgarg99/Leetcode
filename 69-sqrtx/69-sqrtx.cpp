class Solution {
public:
    int mySqrt(int x) {
        long long s=0, e=INT_MAX, ans, mid;
        while(s<=e){
            mid = (s+e)/2;
            
            if(mid*mid==x) return mid;
            if(mid*mid > x){
                e=mid-1;
            }
            else{
                s=mid+1;
                ans=mid;
            }
        }
        return ans;
    }
};