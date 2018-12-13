#include <iostream>
using namespace std;
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        double tN = 0.1;
        for (int t = x; t > 0; t /= 10) {
            tN *= 10;
        }
        int N = tN;
        int upper, lower, t = x;
        while (t > 0) {
            upper = t / N;
            lower = t % 10;
            if (upper != lower) {
                return false;
            }
            t = (t - upper * N) / 10;
            N /= 100;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(121);
}