#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
   public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int startIndex = 0;
        for (startIndex = 0; startIndex < str.size(); ++startIndex) {
            if (str[startIndex] == '-' || str[startIndex] == '+' ||
                ('0' <= str[startIndex] && str[startIndex] <= '9')) {
                break;
            } else {
                if (str[startIndex] != ' ') {
                    return 0;
                }
            }
        }
        if (startIndex == str.size()) return 0;
        stringstream s;
        s << str.substr(startIndex);
        int n=0;
        s >> n;
        return n;
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("+1");
}