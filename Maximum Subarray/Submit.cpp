#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        int result=INT32_MIN;
        int dp[n+1];
        for(int i=0; i <= n; ++i){
            dp[i] = 0;
        }
        for(int i=1; i <= n; ++i){
            dp[i] = max(nums[i-1]+dp[i-1], nums[i-1]);
            result = max(dp[i], result);
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