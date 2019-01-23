#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        if (candidates.empty() || candidates[0] > target) {
            return result;
        }
        int r = candidates.size() - 1;
        while (candidates[r] > target) {
            --r;
        }
        if (candidates[r] == target) {
            result.push_back(vector<int>(1, target));
            --r;
        }
        candidates.resize(r + 1);
        solve(result, candidates, target, vector<int>(), 0);
        return result;
    }
    void solve(vector<vector<int>>& result, const vector<int>& candidates,
               int target, vector<int> tempResult, int i) {
        for (; i < candidates.size(); ++i) {
            if (candidates[i] == target) {
                result.push_back(add(tempResult, candidates[i]));
                return;
            }
            if (candidates[i] < target) {
                solve(result, candidates, target - candidates[i],
                      add(tempResult, candidates[i]), i);
            }
            if (candidates[i] > target) {
                return;
            }
        }
    }
    vector<int> add(vector<int> a, int b) {
        a.push_back(b);
        return a;
    }
};

int main() {
    Solution s;
    vector<int> a = {2, 3, 6, 7};
    for (vector<int>& i : s.combinationSum(a, 7)) {
        for (int& j : i) {
            cout << j << "   ";
        }
        cout << endl;
    }
    return 0;
}