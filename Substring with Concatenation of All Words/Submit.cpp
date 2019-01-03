#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

static const auto disable_sync = []() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty() || s.size() < words.size()) {
            return result;
        }
        map<int, string> indexTable;
        map<string, int> countTable;
        int totalLength = 0;
        for (auto i = words.begin(); i != words.end();) {
            totalLength += (*i).size();
            if (totalLength > s.size()) {
                return result;
            }
            if (countTable[*i] > 0) {
                ++countTable[*i];
                i = words.erase(i);
            } else {
                ++countTable[*i];
                if (!findSubstring(s, *i, indexTable)) {
                    return result;
                }
                ++i;
            }
        }
        for (auto i = indexTable.begin(); i != indexTable.end(); ++i) {
            if (i->first + totalLength - 1 >= s.size()) {
                break;
            }
            if (match(s, indexTable, countTable, i->first,
                      i->first + totalLength - 1)) {
                result.push_back(i->first);
            }
        }
        return result;
    }

   private:
    bool findSubstring(string s, string word, map<int, string>& indexTable) {
        bool found = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == word[0] && s.substr(i, word.size()) == word) {
                indexTable[i] = word;
                found = true;
            }
        }
        return found;
    }

    bool match(string s, map<int, string>& indexTable,
               map<string, int> countTable, int index, int end) {
        string curWord = indexTable[index];
        while (countTable[curWord]-- > 0 && curWord != "") {
            index = index + curWord.size();
            curWord = indexTable[index];
            if (index > end) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<string> a = {"word", "good", "best", "good"};
    string c = "wordgoodgoodgoodbestword";
    if (0) {
        ifstream f("data");
        f >> c;
        a.clear();
        string c;
        int i = 0;
        while (f >> c) {
            if (c.empty()) break;
            a.push_back(c);
            c.clear();
        }
        f.close();
    }
    for (int i : s.findSubstring(c, a)) {
        cout << i << "   ";
    }
    return 0;
}