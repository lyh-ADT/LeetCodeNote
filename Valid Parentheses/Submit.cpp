#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

static const auto disable_sync = []() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    bool isValid(string s) {
        if (s.size() % 2) return false;
        stack<char> st;
        for (char c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    st.push(c);
                    break;
                case ')':
                case ']':
                case '}':
                    if (st.empty() || Parenthesis.at(st.top()) != c) {
                        return false;
                    } else {
                        st.pop();
                    }
                    break;
                default:
                    break;
            }
        }
        return st.empty();
    }

   private:
    const map<char, char> Parenthesis = {
        make_pair('(', ')'), make_pair('[', ']'), make_pair('{', '}')};
};

int main() {
    Solution s;
    cout << boolalpha << s.isValid("]{");
    return 0;
}