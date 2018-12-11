#include <iostream>
using namespace std;

class Solution {
   public:
    const int MAX_INT = 2147483647;
    int reverse(int x) {
        // getLength
        int length = 0;
        int result = 0;
        double tbit = 0.1;
        for (int t = abs(x); t > 0; t /= 10, length++) {
            tbit *= 10;
        }
        int bit = tbit;
        int tMax = MAX_INT;
        bool unsurerange = true;
        for (int t = abs(x); t > 0; t /= 10) {
            if (length == 10 && unsurerange) {
                // checkRange
                if (t % 10 > tMax / bit) {
                    return 0;
                } else {
                    if (t % 10 < tMax / bit) {
                        unsurerange = false;
                    }
                }
                tMax = tMax % bit;
            }
            result += t % 10 * bit;
            bit /= 10;
        }
        if (x < 0) {
            return -result;
        } else {
            return result;
        }
    }
};

int main() {
    Solution s;
    cout << s.reverse(-2147483412);
}