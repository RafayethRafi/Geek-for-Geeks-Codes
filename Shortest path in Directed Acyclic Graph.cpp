//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     void topo(int node, vector<pair<int,int>>adj[],int vis[],stack<int> &st)
     {
         vis[node] = 1;
         
         for(auto u : adj[node])
         {
             if(!vis[u.first])
             {
                 topo(u.first,adj,vis,st);
             }
         }
         st.push(node);
     }
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        
        int vis[N] = {0},i;
        
        for(i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        stack<int> st;
        
        for(i=0;i<N;i++)
        {
            if(!vis[i])
            {
                topo(i,adj,vis,st);
            }
        }
        
        vector<int> dist(N,1e9);
        dist[0] = 0;
        
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto u:adj[node])
            {
                int x = u.first;
                int wt = u.second;
                
                if(dist[node] + wt < dist[x])
                {
                    dist[x] = dist[node] + wt;
                }
            }
        }
        
        vector<int> ans(N,-1);
        for(i=0;i<N;i++)
        {
            if(dist[i] != 1e9)
            {
                ans[i] = dist[i];
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
