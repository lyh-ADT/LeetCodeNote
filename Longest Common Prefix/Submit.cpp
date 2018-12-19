#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string result = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;
            for (; j < strs[i].size(); ++j) {
                if (j >= result.size() || result[j] != strs[i][j]) {
                    break;
                }
            }
            result.resize(j, 0);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> a = {"ff","fff","fff"};
    cout << s.longestCommonPrefix(a);
}