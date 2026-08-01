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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast =  head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev =  nullptr;
        ListNode* current = slow->next;
        slow->next = nullptr;

        while(current != NULL){
            ListNode* newtemp = current->next;
            current->next = prev;
            prev = current;
            current = newtemp;
        }
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second -> next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
        
    }
};