#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> a) {
    for (vector<char>& i : a) {
        for (char& j : i) {
            cout << j << "  ";
        }
        cout << endl;
    }
}

static const auto disable_sync = []() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    const int length = 9;
    void solveSudoku(vector<vector<char>>& board) {
        vector<short> row(9, 0);
        vector<short> column(9, 0);
        vector<short> _3x3(9, 0);
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                if (board[i][j] != '.') {
                    short current = 1 << (board[i][j] - '0');
                    int tt = ((i / 3) * 3) + (j / 3);
                    row[i] |= current;
                    column[j] |= current;
                    _3x3[tt] |= current;
                }
            }
        }
        solve(board, 0, 0, row, column, _3x3);
    }

    bool solve(vector<vector<char>>& board, int i, int j, vector<short>& row,
               vector<short>& column, vector<short>& _3x3) { 
        if (i >= length) {
            return true;
        }
        if (board[i][j] == '.') {
            for (int t = 1; t <= length; ++t) {
                short current = 1 << t;
                int tt = ((i / 3) * 3) + (j / 3);

                if ((row[i] & current) == 0 && (column[j] & current) == 0 &&
                    (_3x3[tt] & current) == 0) {
                    row[i] |= current;
                    column[j] |= current;
                    _3x3[tt] |= current;
                    board[i][j] = '0' + t;
                    if (length - j == 1) {
                        if (solve(board, i + 1, 0, row, column, _3x3)) {
                            return true;
                        }
                    } else {
                        if (solve(board, i, j + 1, row, column, _3x3)) {
                            return true;
                        }
                    }
                    row[i] ^= current;
                    column[j] ^= current;
                    _3x3[tt] ^= current;
                    board[i][j] = '.';
                }
            }
        } else {
            if (length - j == 1) {
                return solve(board, i + 1, 0, row, column, _3x3);
            } else {
                return solve(board, i, j + 1, row, column, _3x3);
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> a = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    s.solveSudoku(a);
    printBoard(a);
    return 0;
}