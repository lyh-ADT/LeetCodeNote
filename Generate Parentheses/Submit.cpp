#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        getParenthesis(result, n);
        return result;
    }
    void getParenthesis(vector<string>& result, int const n, string s = "",
                        int right = 0, int left = 0) {
        if (s.size() == 2 * n) {
            result.push_back(s);
            return;
        }
        if (left < n) {
            getParenthesis(result, n, s + "(", right, left + 1);
        }
        if (right < left) {
            getParenthesis(result, n, s + ")", right + 1, left);
        }
    }
};

int main() {
    Solution s;
    for (string i : s.generateParenthesis(3)) {
        cout << i << endl;
    }
    return 0;
}