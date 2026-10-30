class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            unordered_set<char> seen;
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if(val == '.') continue;
                if(seen.find(val) != seen.end()){
                    return false;
                }
                seen.insert(val);
            }
        }
        for (int c = 0; c < 9; c++) {
            unordered_set<char> seen;
            for (int r = 0; r < 9; r++) {
                char val = board[r][c];
                if(val == '.') continue;
                if(seen.find(val) != seen.end()){
                    return false;
                }
                seen.insert(val);
            }
        }
        for (int box_r = 0; box_r < 9; box_r += 3) {
            for (int box_c = 0; box_c < 9; box_c += 3) {
                unordered_set<char> seen;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[box_r + i][box_c + j];
                        if(val == '.') continue;
                        if(seen.find(val) != seen.end()){
                            return false;
                        }
                        seen.insert(val);
                    }
                }
            }
        }
        return true;
    }
};
