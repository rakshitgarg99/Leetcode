class Solution {
public:
//     bool canFinish(int n, vector<vector<int>>& pre) {
//         vector<int> adj[n];
//         vector<int> indegree(n);
//         for(auto it : pre){
//             adj[it[1]].push_back(it[0]);
//             indegree[it[0]]++;
//         }
        
//         queue<int> q;
//         for(int i=0;i<n;i++){
//             if(indegree[i]==0) q.push(i);
//         }
        
//         vector<int> topo;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
            
//             // n--;
//             topo.push_back(node);
            
//             for(auto it : adj[node]){
//                 indegree[it]--;
//                 if(indegree[it]==0) q.push(it);
//             }
//         }
        
//         return topo.size()==n;
        
//     }
    
    
    
    bool hascycle(vector<int> adj[], int i, vector<int> &vis, vector<int> &dfsvis){
    vis[i]=1;
    dfsvis[i]=1;
    
    for(auto x:adj[i]){
        if(!vis[x]){
            if(hascycle(adj,x,vis,dfsvis)) return true;
        }
        else if(dfsvis[x]) return true;
    }
    
    dfsvis[i]=0;
    return false;
}
    
    bool canFinish(int n, vector<vector<int>>& pre){
        vector<int> adj[n+1];
    for(int i=0;i<pre.size();i++){
        adj[pre[i][0]].push_back(pre[i][1]);
    }
    
    vector<int> vis(n+1,0), dfsvis(n+1,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(hascycle(adj,i,vis,dfsvis)) return false;
        }
    }
    return true;
    }
    
    
    
};