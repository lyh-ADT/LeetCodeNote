#include <iostream>
#include <vector>
using namespace std;

static const auto disable_sync = [](){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
  public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int m = A.size();
        int n = B.size();
        if (m > n) {
            swap(A, B);
            swap(m, n);
        }
        int iMax = m, iMin = 0;
        int halfLen = (n + m + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && B[j - 1] > A[i]) {
                iMin = i + 1;
            } else if (i > iMin && A[i - 1] > B[j]) {
                iMax = i - 1;
            } else {
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = B[j - 1];
                } else if (j == 0) {
                    maxLeft = A[i - 1];
                } else {
                    maxLeft = max(A[i - 1], B[j - 1]);
                }

                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == m) {
                    minRight = B[j];
                } else if (j == n) {
                    minRight = A[i];
                } else {
                    minRight = min(A[i], B[j]);
                }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 3,};
    vector<int> b = {2};
    cout << s.findMedianSortedArrays(a, b);
    return 0;
}