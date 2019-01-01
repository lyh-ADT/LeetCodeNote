#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        for (int i = 0; i < haystack.size(); ++i) {
            int j = 0;
            int t = i;
            while (j < needle.size()) {
                if (haystack[i] == needle[j]) {
                    ++j;
                    ++i;
                } else {
                    i = t;
                    break;
                }
            }
            if (j == needle.size()) {
                return t;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("hello", "ll");
    return 0;
}
