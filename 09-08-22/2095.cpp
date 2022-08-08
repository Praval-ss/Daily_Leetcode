// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/


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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head || !head->next){
            return NULL;
        }
        
        ListNode* ans=head, *slow=head, *fast=head->next, *prev=NULL;
        
        
        while(fast->next && fast->next->next){
            
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
            
        }
        prev=slow;
        slow=slow->next;
        
        prev->next=slow->next;
        slow->next=NULL;
        
        return head;
        
    }
};