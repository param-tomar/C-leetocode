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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;

        // Phase 1: Determine if a cycle exists using slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        // If no cycle was found, return null
        if (!hasCycle) {
            return nullptr;
        }

        // Phase 2: Find the entry node of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // Both pointers now meet at the cycle start
    }
};