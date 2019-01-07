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
        int t = bSearch(nums, target, 0, nums.size() - 1);
        if (t == -1) {
            return vector<int>{-1, -1};
        }
        int right = bSearch(nums, target, t + 1, nums.size() - 1);
        int left = bSearch(nums, target, 0, t - 1);
        int first = t, last = t;
        while (right > -1) {
            last = right;
            right = bSearch(nums, target, right + 1, nums.size() - 1);
        }
        while (left > -1) {
            first = left;
            left = bSearch(nums, target, 0, left - 1);
        }
        return vector<int>{first, last};
    }
    int bSearch(vector<int>& nums, int target, int i, int j) {
        while (i <= j) {
            int k = (i + j) >> 1;
            if (nums[k] == target) {
                return k;
            }
            if (nums[k] < target) {
                i = k + 1;
            } else {
                j = k - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> a = {4,5, 5, 7};
    for (int i : s.searchRange(a, 5)) {
        cout << i << "   ";
    }
    return 0;
}