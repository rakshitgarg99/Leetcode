class Solution {
public:
    
    
    bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {
                return false; 
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        
        int v=graph.size();
        vector<int> adj[v];
        for(int i=0;i<v;i++){
            for(auto x:graph[i]){
                adj[i].push_back(x);
                adj[x].push_back(i);
            }
        }
        
        
        // vector<int> color(v,-1);
        int color[v];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<v;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true;
    }
};