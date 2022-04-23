class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long ntemp=n;
        
        if(n<0) ntemp= -ntemp;
        
        // for(int i=0;i<ntemp;i++){
        //     ans*=x;
        // }
        
        while(ntemp!=0){
            if(ntemp%2==0){
                x=x*x;
                ntemp/=2;
            }
            else{
                ans=ans*x;
                ntemp-=1;
            }
        }
        
        if(n<0) ans=1.0/ans;
        return ans;
    }
};