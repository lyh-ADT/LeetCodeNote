#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int N = height.size() - 1;
        int i = 0;
        int max = 0;
        int cur = 0;
        while (i != N) {
            if (height[i] > height[N]) {
                cur = height[N] * (N - i);
                --N;
            } else {
                cur = height[i] * (N - i);
                ++i;
            }
            if (cur > max) {
                max = cur;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> a = {3, 8};
    cout << s.maxArea(a);
}