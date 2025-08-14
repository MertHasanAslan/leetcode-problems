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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int plus = 0;
        int sum = 0;

        ListNode* curr = new ListNode();
        ListNode* dummy_head = curr;
        while(l1 != nullptr && l2 != nullptr){
            sum = (l1->val + l2->val + plus)%10;
            plus = (l1->val + l2->val + plus)/10;
            curr->next = new ListNode(sum, nullptr);
            curr = curr->next; l1 = l1->next; l2 = l2->next;
        }
        while(l1 != nullptr){
            sum = (l1->val+ plus)%10;
            plus = (l1->val + plus)/10;
            curr->next = new ListNode(sum, nullptr);
            curr = curr->next; l1 = l1->next;
        }
        while(l2 != nullptr){
            sum = (l2->val+ plus)%10;
            plus = (l2->val + plus)/10;
            curr->next = new ListNode(sum, nullptr);
            curr = curr->next; l2 = l2->next;
        }
        if (plus != 0){
            curr->next = new ListNode(plus, nullptr);
        }

        return dummy_head->next;
    }
};
