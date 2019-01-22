#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string s = countAndSay(n - 1);
        string news;
        int i = 0;
        while (i < s.size()) {
            int c = 1;
            while (i < s.size() && s[i] == s[++i]) {
                ++c;
            }
            news += string(1, c + '0') + string(1, s[i - 1]);
        }
        return news;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(6);
    return 0;
}