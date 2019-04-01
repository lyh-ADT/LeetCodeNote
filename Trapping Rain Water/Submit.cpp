#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> a) {
    for (int &i : a) {
        cout << i << "\t";
    }
    cout << endl;
}

static const int disable_sync = []() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
  public:
    int trap(vector<int> &height) {
        const int n = height.size();
        vector<int> left(n), right(n);
        for (int i = 1; i < n - 1; ++i) {
            left[i] = max(left[i - 1], height[i - 1]);
            right[n - i - 1] = max(right[n - i], height[n - i]);
        }
        int result = 0;
        for (int i = 1; i < n - 1; ++i) {
            int t = min(left[i], right[i]) - height[i];
            result += max(t, 0);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> a = {6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2,
                     7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3};
    cout << s.trap(a);
    return 0;
}