class Solution {
public:
    
    bool solve(vector<int>& mstk, int target, vector<int> &side, int idx){
        if(idx==mstk.size()){
            if(side[0]==side[1] and side[1]==side[2] and side[2]==side[3]){
                return true;
            }
            return false;
        }
        
        
        for(int i=0;i<4;i++){
            if(side[i] + mstk[idx] > target){
                continue;
            }
            
            int j=i-1;
            while(j>=0){
                if(side[j]==side[i]){
                    break;
                }
                j--;
            }
            
            if(j!=-1){
                continue;
            }
            
            side[i]+=mstk[idx];
            if(solve(mstk,target,side,idx+1)){
                return true;
            }
            side[i]-=mstk[idx];
        }
        return false;
    }
    
    
    bool makesquare(vector<int>& mstk) {
        if(mstk.size()==0) return false;
        
        int sum=0;
        for(auto x:mstk){
            sum+= x;
        }
        int target=sum/4;
        vector<int> side(4,0);
        
        
        sort(mstk.begin(), mstk.end(), greater<int>());
        return solve(mstk, target, side, 0);
    }
};