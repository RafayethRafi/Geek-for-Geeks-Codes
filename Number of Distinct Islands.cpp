class Solution {
  public:
  
  void dfs(int row, int col, vector < vector < int >> & vis,
      vector < vector < int >> & grid, vector < pair < int, int >> & v, int row0, 
      int col0)
  {
      int n = grid.size();
      int m= grid[0].size();
      
      vis[row][col] = 1;
      
      v.push_back( {row-row0,col-col0});
      
      int dx[] = {-1,0,1,0};
      int dy[] = {0,-1,0,1};
      
      for(int k=0;k<4;k++)
      {
          int x = row+ dx[k];
          int y = col+ dy[k];
          
          if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]==1)
          {
              dfs(x,y,vis,grid,v,row0,col0);
          }
          
      }
  }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(),i,j;
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>> st;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>> v;
                    dfs(i,j,vis,grid,v,i,j);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};
