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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> cLists = lists;
        ListNode* h = NULL;
        ListNode* tail = NULL;
        while (cLists.size() > 1) {
            //找出最小的
            auto min = cLists.begin();
            for (auto i = cLists.begin(); i != cLists.end();) {
                if (!(*i)) {  // 如果指向NULL, 移出数组
                    i = cLists.erase(i);
                    continue;
                }
                printList(*i);
                if ((*min)->val > (*i)->val) {
                    min = i;
                }
                ++i;
            }
            cout << "--------------" << endl;
            if (*min == NULL) break;
            if (!h) {
                h = new ListNode((*min)->val);
                tail = h;
                *min = (*min)->next;
                continue;
            }
            printList(h);
            if (tail) tail->next = *min;
            tail = *min;
            *min = (*min)->next;
        }
        if (tail)
            tail->next = cLists[0];
        else if (!cLists.empty()) {
            return cLists[0];
        }
        return h;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = {{1}, {0}};
    vector<ListNode*> vL;
    for (vector<int> i : a) {
        vL.push_back(createList(i));
    }
    printList(s.mergeKLists(vL));
    return 0;
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