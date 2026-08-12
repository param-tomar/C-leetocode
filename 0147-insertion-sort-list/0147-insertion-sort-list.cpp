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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode dummy(0); // Dummy node to act as the start of the sorted list
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* prev = &dummy;

            // Find the right place to insert the current node
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Save the next node to process
            ListNode* nextTemp = curr->next;

            // Insert curr into the sorted section
            curr->next = prev->next;
            prev->next = curr;

            // Move to the next node in the original list
            curr = nextTemp;
        }

        return dummy.next;
    }
};
    