#include <iostream>
#include <vector>
using namespace std;

static const auto disable_sync = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>{-1, -1};
        }
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] == target && nums[j] == target) {
                break;
            }
            if (nums[i] < target) {
                ++i;
            }
            if (nums[j] > target) {
                --j;
            }
        }
        if (i >= j && nums[i] != target) {
            return vector<int>{-1, -1};
        } else {
            return vector<int>{i, j};
        }
    }
};

int main() {
    Solution s;
    vector<int> a = {5, 7};
    for (int i : s.searchRange(a, 6)) {
        cout << i << "   ";
    }
    return 0;
}