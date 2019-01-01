#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        auto i = nums.begin();
        while (i != nums.end()) {
            if (*i == val) {
                i = nums.erase(i);
            } else {
                ++i;
            }
        }
        return nums.size();
    }
};

int main() {
    Solution s;
    vector<int> a = {};
    cout << s.removeElement(a, 2) << endl;
    for (int i : a) {
        cout << i << "   ";
    }
    return 0;
}