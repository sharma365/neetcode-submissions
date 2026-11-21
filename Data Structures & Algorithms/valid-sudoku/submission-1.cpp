class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> square[9];
        for(int r=0;r<=8;r++){
            for(int c=0;c<=8;c++){
                if(board[r][c]=='.')
                    continue;
                int boxid = (r/3)*3+(c/3);
                if((row[r].find(board[r][c])!=row[r].end()) || (col[c].find(board[r][c])!=col[c].end()) || (square[boxid].find(board[r][c])!=square[boxid].end()))
                    return false;
                
                row[r].insert(board[r][c]);
                col[c].insert(board[r][c]);
                square[boxid].insert(board[r][c]);
            }
        }
        return true;
    }
};