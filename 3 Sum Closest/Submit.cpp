#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for (int i : nums) {
            cout << i << "   ";
        }
        cout << endl << "-------------------" << endl;
        int i = 0;
        int result;
        int distance = INT32_MAX;
        while (i < nums.size() - 2) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int tempResult = nums[i] + nums[j] + nums[k];
                int tempDistance = abs(tempResult - target);
                cout << i << " " << j << " " << k << endl;
                cout << tempResult << "   " << tempDistance << endl;
                if(tempResult == target){
                    return target;
                }
                if (tempDistance < distance) {
                    result = tempResult;
                    distance = tempDistance;
                }
                if (tempResult < target) {
                    while (nums[j] == nums[++j]);
                } else {
                    while (nums[k] == nums[--k]);
                }
            }
            while (nums[i] == nums[++i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = {
       0,2,1,-3
    };
    cout << s.threeSumClosest(v, 1);
}