#include <iostream>
using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        if(n < 3){
            return n;
        }
        int dp[n+1]={0,1,2};
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        for (int i = 1; i <= n; ++i) {
            cout << dp[i] << endl;
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(20);
    return 0;
}