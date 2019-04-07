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
    int jump(vector<int> &nums) {
        const int n = nums.size();
        if (n < 2)
            return 0;
        int steps = 0;
        int cur_position = 0;
        int cur_max_reach = nums[0];
        for (int i = 0; i < n; ++i) {
            cur_max_reach = max(i + nums[i], cur_max_reach);
            if (cur_max_reach >= n - 1)
                return steps + 1;
            if (i == cur_position) {
                ++steps;
                cur_position = cur_max_reach;
            }
        }
        return steps;
    }
};

int main() {
    Solution s;
    vector<int> a = {1,1,1,1};
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << "  ";
    }
    cout << endl;
    for (int i = 0; i < a.size(); ++i) {
        cout << i << "  ";
    }
    cout << endl;
    cout << s.jump(a);
    return 0;
}