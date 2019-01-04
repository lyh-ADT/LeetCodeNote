#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int big = -1;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i-1] < nums[i]) {
                big = i-1;
                break;
            }
        }
        if (big == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        int small = -1;
        for (int i = nums.size() - 1; i > -1; --i) {
            if (nums[i] > nums[big]) {
                small = i;
                break;
            }
        }
        int t = nums[big];
        nums[big] = nums[small];
        nums[small] = t;
        sort(nums.begin()+big+1, nums.end());
    }
};

int main() {
    Solution s;
    vector<int> a = {1,3,2};
    s.nextPermutation(a);
    for (int i : a) {
        cout << i << "  ";
    }
    return 0;
}
