//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        vector<int> dist(n+1, 1e9), par(n+1);
        for(int i=1;i<=n;i++) par[i] = i;
        
        dist[1] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,1});
        while(!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            for(auto u : adj[node])
            {
                int adjNode = u.first;
                int edWt = u.second;
                
                if( dist[node] + edWt < dist[adjNode] )
                {
                    dist[adjNode] = dist[node] + edWt;
                    pq.push({dist[adjNode], adjNode});
                    par[adjNode] = node;
                }
            }
        }
        
        if(dist[n] == 1e9) return {-1};
        
        vector<int> ans;
        int node = n;
        while(par[node] != node)
        {
            ans.push_back(node);
            node = par[node];
        }
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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
