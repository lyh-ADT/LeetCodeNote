#include <iostream>
#include <string>
#include<cstring>
using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        bool dp[p.length()+1][s.length()+1];
        dp[0][0] = true;
        for(int i = 1;i <= s.length();i++){
            dp[0][i] = false;
        }
        for(int i=1; i <= p.length(); ++i){
            switch (p[i-1])
            {
                case '*':
                    dp[i][0] = dp[i-1][0];
                    for(int j=1; j <= s.length(); ++j){
                        dp[i][j] = (dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1]);
                    }
                    break;
                case '?':
                    dp[i][0] = false;
                    for(int j=1; j <= s.length(); ++j){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    break;
                default:
                    dp[i][0] = false;
                    for(int j=1; j <= s.length(); ++j){
                        cout << s[j-1] << p[i-1] << endl;
                        dp[i][j] = (s[j-1] == p[i-1] && dp[i-1][j-1]);
                    }
                    break;
            }
        }
        for(int i=0; i <= p.length(); ++i){
            for(int j=0; j <= s.length(); ++j){
                cout << dp[i][j]<<"   ";
            }
            cout << endl;
        }
        return dp[p.length()][s.length()];
    }
};

int main() {
    Solution s;
    cout << boolalpha << s.isMatch("",
"*?");
    return 0;
}