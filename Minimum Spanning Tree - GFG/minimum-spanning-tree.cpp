// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    // int spanningTree(int v, vector<vector<int>> adj[])
    // {
    //     // code here
    //     vector<int> parent(v,-1), key(v,INT_MAX);
    //     vector<bool> mst(v,false);
    //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
    //     key[0]=0; parent[0]=-1;
    //     pq.push({0,0});
        
    //     while(!pq.empty()){
    //         int u=pq.top().second;
    //         pq.pop();
    //         mst[u]=true;
    //         for(auto it:adj[u]){
    //             int v=it[0];
    //             int wt=it[1];
    //             if(mst[v]==false and wt<key[v]){
    //                 parent[v]=u;
    //                 key[v]=wt;
    //                 pq.push({key[v],v});
    //             }
    //         }
    //     }
        
    //     int sum=0;
    //     for(int i=1;i<v;i++){
    //         sum+=key[i];
    //         // cout<<parent[i]<<" ";
    //     }
    //     return sum;
    // }
    
    
    struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int findPar(int x, vector<int> &parent){
    return (x == parent[x]) ? x : parent[x] = findPar(parent[x], parent);
    // if(x == parent[x]) return x;
    
    // return parent[x] = findPar(parent[x]);
}
void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<node> edges; 
// 	edges.push_back(node(0,1,2));
    for(int i = 0; i<V; i++){
        for(auto it : adj[i]){
            int u = i;
            for(int y = 0; y<it.size(); y++){
                int v = it[0];
                int wt = it[1];
                edges.push_back(node(u, v, wt));
            }
        }
    }
	sort(edges.begin(), edges.end(), [](node a, node b){
	    return (a.wt<b.wt);
	}); 
	int N = V+1;
	vector<int> parent(N);
	for(int i = 0;i<N;i++) 
	    parent[i] = i; 
	vector<int> rank(N, 0); 
    int sum = 0;
    for(auto it: edges){
        
        if(findPar(it.u, parent)!=findPar(it.v, parent)){
            unionn(it.u, it.v, parent, rank);
            sum+=it.wt;
        }
    }
    return sum;
        // code here
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends