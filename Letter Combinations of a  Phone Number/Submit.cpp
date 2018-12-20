#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <class T>
void outputVector(vector<T> v);
class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        for (int i = 0; i < digits.size(); ++i) {
            string digit_str =
                TABLE[digits[i] - '0'];  // 每一位字符对应的每个字母
            if (result.empty()) {
                for (char t : digit_str) {
                    result.push_back(string(1, t));
                }
                continue;
            }
            vector<string> newResult;
            for (char j = 0; j < digit_str.size(); ++j) {
                for (string& t : result) {
                    newResult.push_back(t + digit_str[j]);
                }
            }
            result = newResult;
        }
        return result;
    }

   private:
    const vector<string> TABLE = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

int main() {
    Solution s;
    vector<string> result = s.letterCombinations("23");
    outputVector(result);
}
template <class T>
void outputVector(vector<T> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v.at(i) << endl;
    }
}
