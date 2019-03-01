#include <iostream>
#include <vector>
using namespace std;

static auto disable_sync = [](){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << dp[i][j] << "    ";
            }
            cout << endl;
        }
        return dp[n - 1][m - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = {
        {1,2,5},
        {3,2,1}};
    cout << s.minPathSum(a);
    return 0;
}