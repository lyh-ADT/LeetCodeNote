#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
   public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i < s.size() - 1 && TABLE.at(s[i + 1]) > TABLE.at(s[i])) {
                result += TABLE.at(s[i + 1]) - TABLE.at(s[i]);
                ++i;
                continue;
            }
            result += TABLE.at(s[i]);
        }
        return result;
    }

   private:
    const map<char, int> TABLE = {map<char, int>::value_type('I', 1),
                                  map<char, int>::value_type('V', 5),
                                  map<char, int>::value_type('X', 10),
                                  map<char, int>::value_type('L', 50),
                                  map<char, int>::value_type('C', 100),
                                  map<char, int>::value_type('D', 500),
                                  map<char, int>::value_type('M', 1000)};
};

int main() {
    Solution s;
    cout << s.romanToInt("XXVII");
}