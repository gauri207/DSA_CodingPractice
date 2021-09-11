class Solution {
public:
    bool isSafe1(int row, int col, vector<string> board, int n) {
        
         //we are inserting Queen Column by column since we dont check for horizontal right
        //vertical up and down. we only check for upper diagonal,lower diagonal and horizontally left
        
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        //check for horizontally left
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--; 
        }
        //check for lower diagonal
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--; 
        }
        
        return true; 
    }
public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        for(int row = 0;row<n;row++) {
            if(isSafe1(row, col, board, n)) {
                board[row][col] = 'Q';      //do
                solve(col+1, board, ans, n);//recursion
                board[row][col] = '.';      //backtrack or undo
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;         //whole chess board
        vector<string> board(n);            //sinle col of chess board
        string s(n, '.');                   //string of n size with initialization '.'
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
         
        solve(0,board, ans, n);         //col,board,ans,num.ofrow/col
        return ans; 
    }
    
};