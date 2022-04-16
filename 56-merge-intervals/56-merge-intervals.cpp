class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> arr;
        int start=0, end=0;
        int i=0,j=0;
        
        
        for(i=0;i<intervals.size();){
            start = intervals[i][0];
            end = intervals[i][1];
            
            for(j=i;j<intervals.size();j++){
                if(end >= intervals[j][0]){
                    end = max(end, intervals[j][1]);
                }
                else{
                    break;
                }
            }
            arr.push_back({start, end});
            i = j;
        }
        
        
        // vector<int> v = intervals[0];
        // for(auto x : intervals){
        //     cout<<x[0]<<" ";
        // }
        
        
        return arr;
    }
};