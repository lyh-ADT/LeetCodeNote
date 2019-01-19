#include <iostream>
#include <vector>
using namespace std;

static const auto disable_sync = []() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int r = nums.size() - 1;
        int l = 0;
        while (l < r) {
            int m = (r + l) / 2 + 1;
            if (nums[m] == target) {
                return m;
            }
            if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return nums[l] < target ? l + 1 : l;
    }
};

int main() {
    Solution s;
    vector<int> a = {1};
    cout << s.searchInsert(a, 7);
    return 0;
}