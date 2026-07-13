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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = new ListNode(0);
        current->next = head;
        ListNode* fast = current;
        ListNode* slow = current;
        for(int i=0; i<=n; i++){
            fast = fast->next;
        }
        while(fast != nullptr){
            fast = fast->next;
            slow  = slow->next;
        }
        ListNode* nodeTOdelete = slow->next;
        slow->next = slow-> next ->next;
        delete nodeTOdelete;
        
        ListNode* newhead = current->next;
        delete current;
        return newhead;
        }
};