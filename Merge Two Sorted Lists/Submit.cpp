#include <iostream>
#include <vector>
using namespace std;

static const auto disable_sync = [] {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* h) {
    while (h) {
        if (h->next) {
            cout << h->val << "->";
        } else {
            cout << h->val;
        }
        h = h->next;
    }
    cout << endl;
}

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) { return l2; }
        if (!l2) { return l1; }
        ListNode* h = l1->val < l2->val ? l1 : l2;
        ListNode* tail = NULL;
        while (l1) {
            if (l1->val < l2->val) {
                if (tail) tail->next = l1;
                tail = l1;
                if (l1->next) {
                    l1 = l1->next;
                } else {
                    tail->next = l2;
                    break;
                }
            } else {
                if (tail) tail->next = l2;
                tail = l2;
                if (l2->next) {
                    l2 = l2->next;
                } else {
                    tail->next = l1;
                    break;
                }
            }
        }
        return h;
    }
};

ListNode* createList(vector<int> a) {
    if (a.empty()) return NULL;
    ListNode* h = new ListNode(a[0]);
    ListNode* t = h;
    for (int i = 1; i < a.size(); ++i) {
        t->next = new ListNode(a[i]);
        t = t->next;
    }
    return h;
}

int main() {
    Solution s;
    ListNode* a = createList({1, 2});
    ListNode* b = createList({1, 3, 4});
    printList(s.mergeTwoLists(a, b));
}