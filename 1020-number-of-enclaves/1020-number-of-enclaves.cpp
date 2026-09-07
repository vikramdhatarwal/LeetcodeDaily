class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        stack<pair<int,int>> s;
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                s.push({i,0});
            }
            if(grid[i][n-1]==1){
                s.push({i,n-1});
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                s.push({0,i});
            }
            if(grid[m-1][i]==1){
                s.push({m-1,i});
            }
        }
        while(!s.empty()){
            int x= s.top().first;
            int y= s.top().second;
            grid[x][y]=2;
            s.pop();
            if(x+1<m && !vis[x+1][y] && grid[x+1][y]==1){
                s.push({x+1,y});
                vis[x+1][y]=true;
                
            }
            if(x-1>=0 && !vis[x-1][y] && grid[x-1][y]==1){
                s.push({x-1,y});
                vis[x-1][y]=true;
              
            }
            if(y+1<n && !vis[x][y+1] && grid[x][y+1]==1){
                s.push({x,y+1});
                vis[x][y+1]=true;
        
            }
            if(y-1>=0 && !vis[x][y-1] && grid[x][y-1]==1){
                s.push({x,y-1});
                vis[x][y-1]=true;
          
            }

        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   ans++;
                }
            }
        }
        return ans;
    }
};