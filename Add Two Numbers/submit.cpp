/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = l1->val + l2->val;
        bool carry = val / 10 ? true : false;
        val = val % 10;
        ListNode *t = new ListNode(val);
        ListNode *head = t;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 && l2){
            val = l1->val + l2->val + (carry?1:0);
            carry = val / 10 ? true : false;
            val = val % 10;
            t->next = new ListNode(val);
            t = t->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            val = l1->val + (carry?1:0);
            carry = val / 10 ? true : false;
            val = val % 10;
            t->next = new ListNode(val);
            t = t->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            val = l2->val + (carry?1:0);
            carry = val / 10 ? true : false;
            val = val % 10;
            t->next = new ListNode(val);
            t = t->next;
            l2 = l2->next;
        }
        if(carry){
            t->next = new ListNode(1);
        }
        return head;
    }
};
