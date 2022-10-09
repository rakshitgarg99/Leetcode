class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> deg(n);
        map<int, int> mp;
        for(auto x:roads){
            deg[x[0]]++;
            deg[x[1]]++;
        }
        sort(deg.begin(), deg.end());
        
        
        long long sum=0, i=1;
        
        for(auto x: deg){
            sum+= (x*i);
            i++;
        }
        return sum;
        
    }
};