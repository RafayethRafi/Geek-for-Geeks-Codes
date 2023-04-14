class Solution {
  public:
    bool check(int node,vector<int> adj[], int vis[] )
    {
        vis[node] = 2;
        
        for(auto u:adj[node])
        {
            if(vis[u]==0)
            {
                if(check(u,adj,vis)) return true;
            }
            else if(vis[u] == 2)
            {
                return true;
            }
        }
        
        vis[node] = 1;
        
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(check(i,adj,vis) == true)
                return true;
            }
        }
        
        return false;
    }
};
