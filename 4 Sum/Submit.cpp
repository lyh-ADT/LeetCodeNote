#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {
            int j = nums.size() - 1;
            while (i < j) {
                int lower = i + 1;
                int upper = j - 1;
                while (lower < upper) {
                    int tempSum = nums[i] + nums[j] + nums[lower] + nums[upper];
                    int tempDistance = abs(tempSum - target);
                    cout << i << " " << lower << " " << upper << " " << j
                         << endl;
                    cout << tempSum << "   " << tempDistance << endl;
                    if (tempSum == target) {
                        result.push_back(vector<int>{nums[i], nums[j],
                                                     nums[lower], nums[upper]});
                    }
                    if (tempSum < target) {
                        while (nums[lower] == nums[++lower]) {}
                    } else {
                        while (nums[upper] == nums[--upper]) {}
                    }
                }
                while (nums[j] == nums[--j]) {}
            }
            while (nums[i] == nums[++i]) {}
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = s.fourSum(a, 0);
    for (vector<int> i : result) {
        for (int j : i) { cout << j << "   "; }
        cout << endl;
    }
    return 0;
}