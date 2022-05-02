class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, pair<int,int>> mp;
        
        for(int i=0; i<cards.size(); i++){
            if(mp.find(cards[i])==mp.end()){
                mp[cards[i]]={i,INT_MAX};
            }
            else{
                mp[cards[i]]={i,min((i+1)-mp[cards[i]].first, mp[cards[i]].second)};
            }
        }
        
        int count=INT_MAX;
        for(auto x:mp){
            // cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
            if(x.second.second!=INT_MAX){
                count=min(count, x.second.second);
            }
        }
        // cout<<count;
        return count!=INT_MAX?count:-1;
    }
};