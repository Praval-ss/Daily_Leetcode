// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/


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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        
        vector<int> sol(2,-1);
        if(!head || !head->next || !head->next->next) return sol;
        
        vector<int> v;
        
        int k=1;
        ListNode* prev=head;
        head=head->next;
        ListNode* nxt=head->next;
        
        while(head->next){
            
            if(head->val>prev->val && head->val>nxt->val) v.push_back(k);
            else if(head->val<prev->val && head->val<nxt->val) v.push_back(k);
            
            k++;
            head=head->next;
            prev=prev->next;
            nxt=nxt->next;
            
        }
        
        cout<<v.size()<<endl;
        
        if(v.size()>1){
            sort(v.begin(),v.end());
            // vector<int> sol;

            int mini=INT_MAX;
            for(int i=0;i<v.size()-1;i++){
                mini=min(v[i+1]-v[i],mini);
            }
            int maxi=v[v.size()-1]-v[0];

            sol[0]=mini;
            sol[1]=maxi;
        }
        
        
        return sol;
        
    }
};