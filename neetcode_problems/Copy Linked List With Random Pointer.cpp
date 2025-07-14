/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {return nullptr;}
        if (map.count(head)) {return map[head];}

        Node* dummy = new Node(head->val);
        map[head] = dummy;

        dummy->next = copyRandomList(head->next);
        dummy->random = map[head->random];

        return dummy;
    }








};