#include <iostream>
using namespace std;

static const auto disable_sync = [](){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
   public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT32_MAX;
        }
        unsigned int td = abs(dividend);
        unsigned int tr = abs(divisor);
        if (td < tr) {
            return 0;
        }

        bool negative = false;
        if ((dividend & divisor & INT32_MIN) == 0 &&
            (dividend < 0 || divisor < 0)) {
            negative = true;
        }

        int result = 1;
        if (tr == 1) {
            result = td;
        } else {
            while (td > tr) {
                tr <<= 1;
                result <<= 1;
            }
            if (td < tr) {
                result = (result >> 1) + divide(td - (tr >> 1), abs(divisor));
            }
        }
        if (negative) {
            result = -result;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.divide(10, 3);
    return 0;
}