class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis,int i, int j){
        stack<pair<int,int>> s;
        s.push({i,j});
        vis[i][j]=true;
        while(!s.empty()){
            int x= s.top().first;
            int y= s.top().second;
            s.pop();
            if(x+1<grid.size() && !vis[x+1][y] && grid[x+1][y]=='1'){
                s.push({x+1,y});
                vis[x+1][y]=true;
            }
            if(x-1>=0 && !vis[x-1][y] && grid[x-1][y]=='1'){
                s.push({x-1,y});
                vis[x-1][y]=true;
            }
            if(y+1<grid[0].size() && !vis[x][y+1] && grid[x][y+1]=='1'){
                s.push({x,y+1});
                vis[x][y+1]=true;
            }
            if(y-1>=0 && !vis[x][y-1] && grid[x][y-1]=='1'){
                s.push({x,y-1});
                vis[x][y-1]=true;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ans;

    }
};