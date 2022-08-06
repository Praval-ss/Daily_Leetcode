// https://leetcode.com/problems/split-linked-list-in-parts/submissions/

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
    
    int size(ListNode* root){
        int n=0;
        while(root){
            root=root->next;
                n++;
        }
        return n;
        
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> sol;
        
        int n=size(head);
        int f=n%k;
        
        int noel=n/k;
        
        while(head){
                
            ListNode* l=new ListNode();
            ListNode* ad=l;
            int i=0;
            while(i!=noel && head){
                
                ListNode* newNode=new ListNode(head->val);
                l->next=newNode;
                l=l->next;
                head=head->next;
                i++;
                
            }
            
            if(f && head){
                ListNode* newNode=new ListNode(head->val);
                l->next=newNode;
                l=l->next;
                head=head->next;
                f--;
            }
            
            
            sol.push_back(ad->next);
            
            
        }
        
        if(sol.size()<k){
            while(sol.size()!=k){
                sol.push_back(NULL);
            }
        }
        
        return sol;
        
    }
};