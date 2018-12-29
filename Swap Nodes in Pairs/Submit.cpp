#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(vector<int> a);
void printList(ListNode* h);

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* tail = head;
        head = NULL;
        while (tail && tail->next) {
            if (!head) {
                head = tail->next;
            }
            ListNode* t = tail->next->next;
            ListNode* nextHead = t ? t->next : NULL;
            tail->next->next = tail;
            if (nextHead == NULL && t) {
                tail->next = t;
                tail = NULL;
                break;
            }
            tail->next = nextHead;
            tail = t;
        }
        if (tail) return tail;
        return head;
    }
};

int main() {
    Solution s;
    printList(s.swapPairs(createList(vector<int>{1, 2, 3, 4})));
    return 0;
}

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