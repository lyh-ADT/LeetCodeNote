#include <iostream>
#include <iterator>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(),nums.end()), nums.end());
        return nums.size();
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