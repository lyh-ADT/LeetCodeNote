#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p, int level) {
    if (s.empty() && p.empty()) return true;
    // cout << level << "----" << s << "--" << p << "----" << endl;
    int si = 0;
    for (int i = 0; i < p.size(); ++i) {
        if (i < p.size() - 1 && p[i + 1] == '*') {
            for (int t = 0; t < s.size() - i + 1; ++t) {
                // cout << level << endl;
                // cout << s.substr(si, t) << endl;
                // cout << string(t, p[i]) << endl;
                if (p[i] == '.' || s.substr(si, t) == string(t, p[i])) {
                    if (isMatch(s.substr(si + t), p.substr(i + 2), level + 1)) {
                        return true;
                    }
                } else {
                    break;
                }
            }
            return false;
        } else {
            if (si >= s.size() || s[si] != p[i] && p[i] != '.') {
                return false;
            }
            ++si;
        }
    }
    if (si == s.size()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // mississippi
    string s("mississippi");
    string p("mis*is*ip*.");
    cout << boolalpha << isMatch(s, p, 0);
    return 0;
}
