#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.size() < 3) return result;
        map<int, int> table;
        set<int> a(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            ++table[nums[i]];
        }
        nums.assign(a.begin(), a.end());
        for (int i = 0; i < nums.size(); ++i) {
            map<int, int> temp = table;
            --temp[nums[i]];
            for (int j = i; j < nums.size(); ++j) {
                if (temp[nums[j]] <= 0) {
                    continue;
                } else {
                    --temp[nums[j]];
                }
                if (nums[i] + nums[j] > 0) break;
                int t = -nums[i] - nums[j];
                if (temp[t] > 0) {
                    temp[t] = 0;
                    result.push_back(vector<int>{nums[i], nums[j], t});
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> v = s.threeSum(a);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}