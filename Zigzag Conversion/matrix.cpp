#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    char A[numRows][(s.size() / numRows + 1)*2] = {0};
    memset(A, 0, sizeof(A));
    int col = 0;
    for (int i = 0; i < s.size(); i) {
        for (int r = 0; r < numRows; ++r) {
            A[r][col] = s[i++];

        }
        for (int r = numRows - 2; r > 0; r--) {
            A[r][++col] = s[i++];
        }
        col++;
    }
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < (s.size() / numRows + 1)*2; j++) {
            cout << (A[i][j] ? A[i][j] : '_');
        }
        cout << endl;
    }
}