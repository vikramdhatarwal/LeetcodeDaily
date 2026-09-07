class Solution {
public:

   
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(),vector<int> (mat[0].size(),0));
        vector<vector<bool>> vis(mat.size(),vector<bool> (mat[0].size(),false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]= true;
                }
            }
        }
        while(!q.empty()){
            int x= q.front().first.first;
            int y= q.front().first.second;
            int d= q.front().second;
            ans[x][y]= d;
            q.pop();
            if(x+1<mat.size() && !vis[x+1][y]){
                q.push({{x+1,y},d+1});
                vis[x+1][y]=true;
            }
            if(x-1>=0 && !vis[x-1][y]){
                q.push({{x-1,y},d+1});
                vis[x-1][y]=true;
            }
            if(y+1<mat[0].size() && !vis[x][y+1]){
                q.push({{x,y+1},d+1});
                vis[x][y+1]=true;
            }
            if(y-1>=0 && !vis[x][y-1]){
                q.push({{x,y-1},d+1});
                vis[x][y-1]=true;
            }

        }
        return ans;
    }
};