// WITH BFS :

class Solution {
  public:
    
    bool detect(int src,vector<int> adj[],int vis[])
    {
        vis[src] = 1;
        
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto u : adj[node])
            {
                if(!vis[u])
                {
                    vis[u] = 1;
                    q.push({u,node});
                }
                else if(parent != u)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis))
                return true;
            }
        }
        return false;
    }
};






//   WITH DFS :
class Solution {
  public:
    
    bool dfs(int node,int par,vector<int> adj[],int vis[])
    {
        vis[node] = 1;
        
        for(auto u:adj[node])
        {
            if(!vis[u])
            {
                if(dfs(u,node,adj,vis) == true)
                return true;
            }
            else if(u != par)
            return true;
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,-1,adj,vis))
                return true;
            }
        }
        return false;
    }
};
