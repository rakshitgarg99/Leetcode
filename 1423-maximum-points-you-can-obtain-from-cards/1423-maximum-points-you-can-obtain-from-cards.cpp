class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int total=0;
        
        for(auto x:card){
            total+=x;
        }
        
        int rem=card.size()-k;
        int sum=0;
        for(int i=0;i<rem;i++){
            sum+=card[i];
        }
        
        int mn=sum;
        for(int i=rem;i<card.size();i++){
            sum-=card[i-rem];
            sum+=card[i];
            mn=min(sum,mn);
            
        }
        
        return total-mn;
        
    }
};