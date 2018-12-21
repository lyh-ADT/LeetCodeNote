#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty() || nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << "  ";
        }
        cout << endl << "--------------------" << endl;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                // cout << nums[i] << "  " << nums[j] << endl;
                int k = findSorted(nums, -(nums[i] + nums[j]), j + 1);

                if (k != -1) {
                    result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                }
                while (j < nums.size() - 1 && nums[j] == nums[j + 1]) {
                    ++j;
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return result;
    }

   private:
    int findSorted(vector<int>& nums, int target, int startIndex) {
        for (int i = startIndex; i < nums.size(); ++i) {
            if (nums[i] >= target) {
                if (nums[i] == target) {
                    return i;
                } else if (nums[i] > target) {
                    return -1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> a = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<vector<int>> v = s.threeSum(a);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}