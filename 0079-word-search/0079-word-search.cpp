class Solution {
public:
    bool helper( vector<vector<char>>& board, string word,int i,int j,int idx){
        if(idx==word.size()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '#';

        bool found= helper(board,word,i+1,j,idx+1) || helper(board,word,i,j+1,idx+1) ||helper(board,word,i,j-1,idx+1) || helper(board,word,i-1,j,idx+1);
        board[i][j] = temp;
        return found;

    
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(helper(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};