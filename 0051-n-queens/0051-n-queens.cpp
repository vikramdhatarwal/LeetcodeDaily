class Solution {
public:
    bool is_possible(int i , int j,vector<string > &board,int n ){
        for(int x=0;x<n;x++){
            if(board[x][j]=='Q') return false;
        }
        for (int y=0;y<n;y++){
            if(board[i][y]=='Q') return false;
        }
        for(int x=i,y=j;x>=0 && y>=0;x--,y--){
            if(board[x][y]=='Q') return false;
        }
        for(int x=i, y=j;x>=0 && y<n;x--,y++){
            if(board[x][y]=='Q') return false;
        }
        return true;

    }
    void helper(int i,int n,vector<vector<string >> &ans,vector<string > &board){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(is_possible(i,j,board,n)){
                board[i][j]='Q';
                helper(i+1,n,ans,board);
                board[i][j]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        helper(0,n,ans,board);
        return ans;
    }
};