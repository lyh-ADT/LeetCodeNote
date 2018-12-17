#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string intToRoman(int num) {
        string result = "";
        int times = 1;
        for (int t = num; t > 0; t /= 10) {
            times *= 10;
        }
        times /= 10;
        for (int i = MAXi; i > -1 && num > 0 && times > 0; i--) {
            int highest = num / times;  // 获取最高位
            int temp = num / NUM[i];
            if (temp != 0) {
                if (highest == 9) {
                    result += string(1, CHAR[i - 1]) + string(1, CHAR[i + 1]);
                    num = num - highest * times;
                    times /= 10;
                } else if (highest == 4) {
                    result += string(1, CHAR[i]) + string(1, CHAR[i + 1]);
                    num = num - highest * times;
                    times /= 10;
                } else {
                    result += string(temp, CHAR[i]);
                    num = num - temp * NUM[i];
                    if (highest * times == temp * NUM[i]) times /= 10;
                }
            } else if (highest == 0 && i % 2 == 0) {
                times /= 10;
            }
        }
        return result;
    }

   private:
    const int MAXi = 6;
    const int NUM[7] = {1, 5, 10, 50, 100, 500, 1000};
    const char CHAR[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
};

int main() {
    Solution s;
    cout << s.intToRoman(1004);
}