class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        
        
        long total=0;
        for(auto x:target){
            pq.push(x);
            total+=x;
        }
        
        while(!pq.empty()){
            int maxele = pq.top();
            pq.pop();
            
            long remaintot = total-maxele;
            if(remaintot==1 or maxele==1) return true;
            
            if(remaintot==0 or maxele < remaintot) return false;
            
            int updatemax = (int)(maxele % remaintot);
            if(updatemax==0) return false;
            
            maxele=updatemax;
            pq.push(maxele);
            total=updatemax+remaintot;
        }
        return true;
    }
};