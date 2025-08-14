/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    int number = 0;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);

        helper(dummy, n);
        return dummy->next;
    }


    void helper(ListNode* head, int n){
        if (head == nullptr){
            return;
        }
        helper(head->next, n);
        number++;
        if (n+1 == number){
            head->next = head->next->next;
        }
    }
};
