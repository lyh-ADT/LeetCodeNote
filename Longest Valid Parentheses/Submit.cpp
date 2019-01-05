#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        return max(calc(s, 0, 1, s.size(), '('),
                   calc(s, s.size() - 1, -1, -1, ')'));
    }

    int calc(string chars, int i, int flag, int end, char cTem) {
        int max = 0, sum = 0, currLen = 0, validLen = 0;
        for (; i != end; i += flag) {
            sum += (chars[i] == cTem ? 1 : -1);
            currLen++;
            if (sum < 0) {
                max = max > validLen ? max : validLen;
                sum = 0;
                currLen = 0;
                validLen = 0;
            } else if (sum == 0) {
                validLen = currLen;
            }
        }
        return max > validLen ? max : validLen;
    }
};

int main() {
    Solution s;
    // "()()(((()))"
    cout << s.longestValidParentheses(")()())");
    return 0;
}