#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }
        nums.resize(i);
        return i;
    }
};

int main() {
    Solution s;
    vector<int> a = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << s.removeElement(a, 2) << endl;
    for (int i : a) {
        cout << i << "   ";
    }
    return 0;
}