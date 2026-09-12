
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode Dummy1(0);  // Dummy head for < x list
        ListNode Dummy2(0);   // Dummy head for >= x list
        ListNode* lessptr = &Dummy1;
        ListNode* greterptr = &Dummy2;

        while (head) {
            if (head->val < x) {
                lessptr->next = head;
                lessptr = lessptr->next;
            } else {
                greterptr->next = head;
                greterptr =greterptr->next;
            }
            head = head->next;
        }

        greterptr->next = nullptr;         // End the after list
        lessptr->next = Dummy2.next; // Connect before list to after list

        return Dummy1.next;
    }
};
