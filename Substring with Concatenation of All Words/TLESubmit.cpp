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
        map<int, vector<string>> indexTable;
        map<string, int> countTable;
        int totalLength = 0;
        for(auto i=words.begin(); i!=words.end();){
            
            totalLength += (*i).size();
            if (totalLength > s.size()) {
                return result;
            }
            if(countTable[*i]>0){
                ++countTable[*i];
                i=words.erase(i);
            }
            else{
                ++countTable[*i];
                if(!findSubstring(s, *i, indexTable)){
                    return result;
                }
                ++i;
            }
        }
        cout << totalLength<<endl;
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
    bool findSubstring(string s, string word,
                       map<int, vector<string>>& indexTable) {
        bool found = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == word[0] && s.substr(i, word.size()) == word) {
                indexTable[i].push_back(word);
                found = true;
            }
        }
        return found;
    }

    bool match(string s, map<int, vector<string>>& indexTable,
               map<string, int> countTable, int index, int end) {
        if (index > end) {
            return true;
        }
        for (string i : indexTable[index]) {
            if (countTable[i]-- > 0 &&
                match(s, indexTable, countTable, index + i.size(), end)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<string> a = {"word", "good", "best", "good"};
    for (int i : s.findSubstring("wordgoodgoodgoodbestword", a)) {
        cout << i << "   ";
    }
    return 0;
}