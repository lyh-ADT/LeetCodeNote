#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        int dp[s.size() + 2][s.size() + 2] = {0};
        memset(dp, 0, sizeof(dp));
        int maxLength = -1;
        int maxIndex = -1;
        for (int i = 1; i <= s.size(); ++i) {
            cout << s[i-1] << "  ";
            for (int j = 1; j <= s.size(); ++j) {
                if (s[i - 1] == s[j - 1]) {
                    if (dp[i - 1][j + 1])
                        dp[i][j] = dp[i - 1][j + 1] + 1;
                    else {
                        dp[i][j] = 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
                if (dp[i][j] > maxLength &&
                    s[j - 1] == s[j - 1 + dp[i][j] - 1]) {
                    maxLength = dp[i][j];
                    maxIndex = j - 1;
                }
                cout << dp[i][j] << "  ";
            }
            cout << endl;
        }
        cout << maxIndex << " " << maxLength << endl;
        if (maxLength < 2) {
            return s.substr(0, 1);
        }
        return s.substr(maxIndex, maxLength);
    }
};

int main() {
    Solution s;
    string a = "aacdefcaa";
    cout << "   ";
    for (int i = 0; i < a.size(); ++i) {
        cout<< a[i] << "  ";
    }
    cout << endl;
    cout << s.longestPalindrome(a);
}