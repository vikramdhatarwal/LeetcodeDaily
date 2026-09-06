class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n= board[0].size();
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                s.push({0,i});
            }
            if(board[m-1][i]=='O'){
                s.push({m-1,i});
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                s.push({i,0});
            }
            if(board[i][n-1]=='O'){
                s.push({i,n-1});
            }
        }
        while(!s.empty()){
            int i=s.top().first;
            int j= s.top().second;
            s.pop();
            board[i][j]='#';
            if(i+1<m && board[i+1][j]=='O'){
                s.push({i+1,j});
            }
            if(i-1>=0 && board[i-1][j]=='O'){
                s.push({i-1,j});
            }
            if(j+1<n && board[i][j+1]=='O'){
                s.push({i,j+1});
            }
            if(j-1>=0 && board[i][j-1]=='O'){
                s.push({i,j-1});
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
    }
};