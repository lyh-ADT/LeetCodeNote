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
        int tempResult[num1.size() + num2.size()] = {0};
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                tempResult[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        string result;
        for (int i = num1.size() + num2.size() - 1; i >= 0; --i) {
            tempResult[i - 1] += tempResult[i] / 10;
            result = to_string(tempResult[i] % 10) + result;
        }
        int i = 0;
        while (i < result.size() - 1 && result[i] == '0') {
            ++i;
        }
        return result.substr(i);
    }
};

int main() {
    Solution s;
    cout << s.multiply("1123", "0");
    return 0;
}