#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        nums.resize(i + 1);
        return i + 1;
    }
};

int main() {
    Solution s;
    vector<int> a = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << s.removeDuplicates(a) << endl;
    for (int i : a) {
        cout << i << "   ";
    }
    return 0;
}