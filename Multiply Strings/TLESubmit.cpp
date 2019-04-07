#include <iostream>
#include <string>
using namespace std;

static const auto disable_sync = []() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
  public:
    string multiply(string num1, string num2) {
        string result = "0";
        string tempResult = "0";
        const int n1 = num1.size();
        const int n2 = num2.size();
        for (int i = n1 - 1; i >= 0; --i) {
            tempResult = "0";
            for (int j = n2 - 1; j >= 0; --j) {
                int c1 = num1.at(i) - '0';
                int c2 = num2.at(j) - '0';
                tempResult = add(tempResult, to_string(c1 * c2), n2 - j);
            }
            result = add(result, tempResult, n1 - i);
        }
        if(result[0]=='0'){
            return "0";
        }
        return result;
    }
    string add(string num1, string num2, int index = 1) {
        const int n1 = num1.size();
        const int n2 = num2.size();
        int next = 0;
        int i1 = n1 - index;
        int i2 = n2 - 1;
        string result = num1.substr(i1 + 1);
        i1 = n1 - result.size() - 1;
        while (i1 >= 0 && i2 >= 0) {
            int c1 = num1.at(i1) - '0';
            int c2 = num2.at(i2) - '0';
            char newChar = (c1 + c2 + next) % 10 + '0';
            next = (c1 + c2 + next) / 10;
            result = newChar + result;
            --i1;
            --i2;
        }
        while (i1 >= 0) {
            int c = num1.at(i1) - '0';
            char newChar = (c + next) % 10 + '0';
            next = (c + next) / 10;
            result = newChar + result;
            --i1;
        }
        while (i2 >= 0) {
            int c = num2.at(i2) - '0';
            char newChar = (c + next) % 10 + '0';
            next = (c + next) / 10;
            result = newChar + result;
            --i2;
        }
        if (next > 0) {
            result = char(next + '0') + result;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.multiply("6123", "0");
    return 0;
}