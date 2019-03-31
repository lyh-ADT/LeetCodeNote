#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int dp[n+1][m+1]={0};
        for(int i=0; i <= n; ++i){
            for(int j=0; j <= m; ++j){
                dp[i][j] = 0;
            }
        }
        for(int i=1; i <= n; ++i){
            for(int j=1; j <= m; ++j){
                if(word1[i-1] != word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else{
                    dp[i][j] = 0;
                }
            }
        }
        //  ***************************************
        cout << "        ";
        for(int i=0; i < m; ++i){
            cout << word2[i] << "   ";
        }
        cout << endl<< "    ";
        for(int i=0; i <= n; ++i){
            for(int j=0; j <= m; ++j){
                cout << dp[i][j] << "   ";
            }
            cout << endl << word1[i] << "   ";
        }
        
        return 0;
    }
};

int main(){
    // Solution s;
    // cout << s.minDistance("horse", "ros");
    cout << "?" << endl;
    return 0;
}