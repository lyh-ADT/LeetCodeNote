#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        int result=INT32_MIN;
        int dp[n+1][n+1];
        for(int i=0; i <= n; ++i){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=n; ++j){
                dp[i][j] = max(nums[i-1]+dp[i-1][j-1], nums[i-1]);
                result = max(dp[i][j], result);
            }
        }
        for(int i=0; i <= n; ++i){
            for(int j=0; j <=n; ++j){
                cout << dp[i][j] << "   ";
            }
            cout << endl;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> a={-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(a);
    return 0;
}