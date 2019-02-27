#include <iostream>
#include<vector>
using namespace std;

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int result = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i - 1 == 0) {
                    dp[i][j] = 1;
                } else if (j - 1 == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                result = max(dp[i][j], result);
            }
        }

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                cout << dp[i][j] << "   ";
            }
            cout << endl;
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(7, 3);
    return 0;
}