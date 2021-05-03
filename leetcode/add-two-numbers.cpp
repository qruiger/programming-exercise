/*
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
        struct ListNode *a = l1, *b = l2, *rhead = NULL, *track, *res;
        int carry = 0, sum;
        if (a == NULL && b == NULL)
            return rhead;
        // exhaust one of the longer linked lists or both if len(l1)==len(l2)
        while (a != NULL && b != NULL) {
            sum = a->val + b->val + carry;
            carry = sum / 10;
            struct ListNode* res = new ListNode(sum % 10);
            if (rhead == NULL) {
                rhead = res;
                track = res;
            }
            else {
                track->next = res;
                track = res;
            }
            a = a->next;
            b = b->next;
        }
        // if b is exhausted before a
        while (a != NULL) {
            sum = a->val + 0 + carry;
            carry = sum / 10;
            struct ListNode* res = new ListNode(sum % 10);
            if (rhead == NULL) {
                rhead = res;
                track = res;
            }
            else {
                track->next = res;
                track = res;
            }
            a = a->next;
        }
        // if a exhausted before b
        while (b != NULL) {
            sum = 0 + b->val + carry;
            carry = sum / 10;
            struct ListNode* res = new ListNode(sum % 10);
            if (rhead == NULL) {
                rhead = res;
                track = res;
            }
            else {
                track->next = res;
                track = res;
            }
            b = b->next;
        }
        if (carry == 1) {
            struct ListNode* res = new ListNode(1);
            track->next = res;
            track = res;
        }
        return rhead;
    }
};