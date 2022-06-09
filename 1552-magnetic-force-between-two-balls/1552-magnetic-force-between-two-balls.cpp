class Solution {
public:
    
    
    bool canplace(vector<int> position, int m, int dist){
        int coord=position[0];
        int cnt=1;
        
        for(int i=1;i<position.size();i++){
            if(position[i]-coord >= dist){
                cnt++;
                coord=position[i];
            }
            if(cnt==m) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int n=position.size()-1;
        int low=1;
        int high = position[n]-position[0];
        
        int ans;
        while(low<=high){
            int mid= (low+high)>>1;
            
            if(canplace(position, m, mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        
        
    }
};