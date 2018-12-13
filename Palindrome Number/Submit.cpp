#include<sstream>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        stringstream ss;
        ss << x;
        string s;
        ss >> s;
        int N = s.size();
        for (int i = 0; i < N; ++i){
            if(s[i]!=s[N-i-1]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.isPalindrome(-121);
}