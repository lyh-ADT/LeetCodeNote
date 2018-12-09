#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int i = 0;
        string result;
        for (int r = 1; r <= numRows; ++r) {
            i = r - 1;
            while (i < s.size()) {
                result += s[i];
                int gap = (numRows - r) * 2;

                if (1 < r && r < numRows && i + gap < s.size()) {
                    result += s[i + gap];
                }
                i = i + (numRows - 1) * 2;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << (s.convert("PAYPALISHIRING", 3));
}