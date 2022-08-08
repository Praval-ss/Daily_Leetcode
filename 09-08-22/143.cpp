// https://leetcode.com/problems/reorder-list/

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
    
     ListNode* reverseList(ListNode* head) {
        ListNode *pre = new ListNode(0), *cur = head;
        pre -> next = head;
        while (cur && cur -> next) {
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = temp;
        }
        return pre -> next;
    }
    
    void reorderList(ListNode* head) {
        
        ListNode* temp = head;
    deque<int> d;
 
    
    while (temp != NULL) {
        d.push_back(temp->val);
        temp = temp->next;
    }
 
   
    int i = 0;
    temp = head;
    while (!d.empty()) {
        if (i % 2 == 0) {
            temp->val = d.front();
            d.pop_front();
        }
        else {
            temp->val = d.back();
            d.pop_back();
        }
        i++;
        temp = temp->next; 
    }
    }
};