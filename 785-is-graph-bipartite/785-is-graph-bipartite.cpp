class Solution {
public:
    
    
    bool isbip(vector<int> adj[],int i, int color[]){
    
        if(color[i]==-1) color[i]=1;
        
        for(auto x: adj[i]){
            if(color[x]==-1){
                color[x]=1-color[i];
                if(!isbip(adj,x,color)) return false;
            }
            else if(color[i]==color[x]) return false;
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
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(!isbip(adj,i,color)) return false;
            }
        }
        
        return true;
    }
};