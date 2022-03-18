class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        // if(pre.size()==0) return {0};
        
        vector<int> adj[n];
        vector<int> indegree(n);
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            // n--;
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(topo.size()==n) return topo;
        return {};
    }
};