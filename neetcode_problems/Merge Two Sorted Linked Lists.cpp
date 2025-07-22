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
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        ListNode* new_head = new ListNode(0);
        ListNode* dummy = new_head;

        while(left != nullptr && right != nullptr){
            if (left->val < right->val) { 
                dummy->next = new ListNode(left->val);
                dummy = dummy->next;
                left = left->next;    
            }
            else {
                dummy->next = new ListNode(right->val);
                dummy = dummy->next;
                right = right->next;
            }
        }

        while(left != nullptr){
            dummy->next = new ListNode(left->val);
            dummy = dummy->next;
            left = left->next;
        }

        while(right != nullptr){
            dummy->next = new ListNode(right->val);
            dummy = dummy->next;
            right = right->next;
        }

        return new_head->next;

        
    }
};
