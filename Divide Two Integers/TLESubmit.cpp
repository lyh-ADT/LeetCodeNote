#include <iostream>
using namespace std;

class Solution {
   public:
    int divide(int dividend, int divisor) {
        int result = 0;
        int td = dividend == INT32_MIN ? INT32_MAX : abs(dividend);
        int tr = abs(divisor);
        while (td >= tr) {
            td -= tr;
            ++result;
            if (result == INT32_MAX) {
                return result;
            }
        }
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            return result;
        } else {
            return -result;
        }
    }
};

int main() {
    Solution s;
    cout << s.divide(-2147483648, -1);
    return 0;
}