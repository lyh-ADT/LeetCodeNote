#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> temp;
        ListNode* nodeP = head;
        while (nodeP != NULL) {
            temp.push(nodeP);
            if (temp.size() == n + 2) { temp.pop(); }
            nodeP = nodeP->next;
        }

        if (temp.size() == n) {
            delete[] temp.front();
            temp.pop();
            if (temp.empty()) {
                return NULL;
            } else {
                return temp.front();
            }

        } else {
            ListNode* front = temp.front();
            temp.pop();
            delete[] temp.front();
            temp.pop();
            if (temp.empty()) {
                front->next = NULL;
            } else {
                front->next = temp.front();
            }
            return head;
        }
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2};
    ListNode* head = new ListNode(a[0]);
    ListNode* t = head;
    for (int i = 1; i < a.size(); ++i) {
        t->next = new ListNode(a[i]);
        t = t->next;
    }
    t = s.removeNthFromEnd(head, 2);
    while (t != NULL) {
        ListNode* tt = t;
        cout << t->val << "  ";
        t = t->next;
        delete[] tt;
    }
    return 0;
}