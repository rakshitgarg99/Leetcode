class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         deque<int> q;
//         vector<int> v;
        
//         int i=0, j=0;
//         while(j<nums.size()){
//             while(!q.empty() and q.back()<nums[j]){
//                 q.pop_back();
//             }
//             q.push_back(nums[j]);
            
//             if(j-i+1<k) j++;
            
//             else if(j-i+1==k){
//                 v.push_back(q.front());
//                 if(q.front()==nums[i]){
//                     q.pop_front();
//                 }
//                 i++;
//                 j++;
//             }
//         }
//         return v;
        
        
        priority_queue<pair<int, int>> heap;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            while(!heap.empty() and heap.top().second <= (i-k)){
                heap.pop();
            }
            
            heap.push({nums[i], i});
            if(i>=k-1){
                ans.push_back(heap.top().first);
            }
        }
        return ans;
        
    }
};