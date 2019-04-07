#include <iostream>
#include <vector>
using namespace std;

static const auto disable_sync = [](){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
  public:
    int jump(vector<int> &nums) {
        const int n = nums.size();
        int steps = 0;
        int goal = n - 1;
        while (goal > 0) {
            int t = 0;
            for (int i = goal - 1; i >= 0; --i) {
                if (nums[i] > goal - 1 - i) {
                    t = i;
                }
            }
            goal = t;
            cout << goal << endl;
            ++steps;
        }
        return steps;
    }
};

int main() {
    Solution s;
    vector<int> a = {1};
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