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
    int firstMissingPositive(vector<int> &nums) {
        if (nums.empty()) {
            return 1;
        }
        for (auto i = nums.begin(); i != nums.end();) {
            if (*i <= 0) {
                i = nums.erase(i);
            } else
                ++i;
        }
        bool tag = false;
        for (int i = 0; i < nums.size(); ++i) {
            int t = abs(nums[i]);
            if (t - 1 < nums.size() && nums[t - 1] > 0) {
                nums[t - 1] = -nums[t - 1];
                tag = true;
            }
        }
        if (!tag) {
            return 1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main() {
    Solution s;
    vector<int> a = {7};
    cout << s.firstMissingPositive(a);
    return 0;
}