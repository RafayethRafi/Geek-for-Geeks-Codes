//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node)
    {
        if(node == parent[node])
        return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ul_pu = findPar(u);
        int ul_pv = findPar(v);

        if( ul_pu == ul_pv) return;
        if(rank[ul_pu] < rank[ul_pv])
        {
            parent[ul_pu] = ul_pv;
        }
        else if(rank[ul_pv] < rank[ul_pu])
        {
            parent[ul_pv] = ul_pu;
        }
        else{
            parent[ul_pv] = ul_pu;
            rank[ul_pu]++;
        }
    }

    void unionBySize(int u,int v){
        int ul_pu = findPar(u);
        int ul_pv = findPar(v);

        if( ul_pu == ul_pv) return;

        if(size[ul_pu] < size[ul_pv]){
            parent[ul_pu] = ul_pv;
            size[ul_pv] += size[ul_pu];
        }
        else{
            parent[ul_pv] = ul_pu;
            size[ul_pu] += size[ul_pv];
        }
    }
};




class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<V;i++)
        {
            for(auto it : adj[i])
            {
                int node = i;
                int adjNode = it[0];
                int wt = it[1];
            
                edges.push_back({wt,{node,adjNode}});
            }
        }
        
        DisjointSet ds(V);
        
        sort(edges.begin(),edges.end());
        
        int ans = 0;
        
        for(auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if( ds.findPar(u) != ds.findPar(v) )
            {
                ans += wt;
                ds.unionBySize(u,v);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


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
