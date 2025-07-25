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
      ListNode* reversell(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; 
        }
        ListNode* newhead = reversell(head->next);
        head->next->next = head;
        head->next = NULL; 
        return newhead; 
    }
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*newhead=reversell(slow->next);
        ListNode*first=head;
        ListNode*second=newhead;
        while(second!=NULL)
        {
            if(first->val != second->val)
            {
                reversell(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reversell(newhead);
        return true;
    }
};