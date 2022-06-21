class Solution {
public:
    
//     void solve(vector<int>& h, int i, int bricks, int ladders, int& ans){
        
//         if(i==h.size()-1) return;
        
//         if(h[i]>=h[i+1]){
//             ans++;
//             solve(h,i+1,bricks,ladders,ans);
//         }
//         else{
            
//             int brickneed = (h[i+1] - h[i]);
//             if(bricks>=brickneed){
//                 ans++;
//                 solve(h,i+1,bricks-brickneed,ladders,ans);
//             }
//             else if(ladders>0){
//                 ans++;
//                 solve(h,i+1,bricks,ladders-1,ans);
//             }
//             else{
//                 return;
//             }
//         }
//     }
    
    
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders){        
        // int ans=0;
        // solve(heights,0,bricks,ladders,ans);
        // return ans;
        
        priority_queue<int> pq;
        int i=0;
        for(i=0;i<heights.size()-1;i++){
            if(heights[i+1]<=heights[i]) continue;
            
            int d = heights[i+1]-heights[i];
            if(d<=bricks){
                bricks-=d;
                pq.push(d);
            }
            else if(ladders>0){
                if(pq.size()>0){
                    int x=pq.top();
                    if(x>d){
                        bricks+=x;
                        pq.pop();
                        bricks-=d;
                        pq.push(d);
                    }
                }
                ladders--;
            }
            else{
                break;
            }
        }
        return i;
    }
};