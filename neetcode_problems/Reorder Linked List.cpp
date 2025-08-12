/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} 123456
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head_2 = reverse(slow->next);
        slow->next = nullptr;
        ListNode* head_1 = head;
        

        while(head_2 != nullptr){
            ListNode* temp1 = head_1->next;
            ListNode* temp2 = head_2->next;

            head_1->next = head_2;
            head_2->next = temp1;

            head_1 = temp1;
            head_2 = temp2;
        }

    }

    ListNode* reverse(ListNode* head){
        if (head == nullptr || head->next == nullptr) { return head; }

        ListNode* new_head = reverse(head->next);

        head->next->next = head;
        head->next = nullptr;

        return new_head;
    }
};
