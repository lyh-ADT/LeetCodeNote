#include <iostream>
#include <vector>
using namespace std;

static const auto disable_sync = []() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int length = board.size();
        short row[length] = {0};
        short column[length] = {0};
        short _3x3[length] = {0};
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                short current = 1 << (board[i][j] - '0');
                // row
                if ((row[i] & current) == 0) {
                    row[i] |= current;
                } else {
                    return false;
                }
                // column
                if ((column[j] & current) == 0) {
                    column[j] |= current;
                } else {
                    return false;
                }
                // 3 x 3
                int t = ((i / 3) * 3) + (j / 3);
                if ((_3x3[t] & current) == 0) {
                    _3x3[t] |= current;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> a = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    cout << boolalpha << s.isValidSudoku(a);
    return 0;
}