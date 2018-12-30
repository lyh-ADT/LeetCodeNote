#include <iostream>
#include <stack>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode *tail = head, *h = NULL;
        while (tail) {
            while (st.size() < k) {
                if (!tail) break;
                st.push(tail);
                tail = tail->next;
            }
            ListNode* t = NULL;
            if (st.size() == k) {
                while (st.size() > 0) {
                    if (!h) h = st.top();// 赋值链表头指针
                    if (t) {
                        t->next = st.top();
                    } else {
                        // 这是第k个元素
                        head->next = st.top();
                    }
                    t = st.top();
                    st.pop();
                }
                t->next = tail;
                head = t;
            } else {
                if (!h) h = head;
                break;
            }
        }
        return h;
    }
};

int main() {
    Solution s;
    printList(s.reverseKGroup(createList(vector<int>{1, 2}), 3));
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