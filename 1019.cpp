// https://leetcode.com/problems/next-greater-node-in-linked-list/

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
    
    vector<int> nextLargerNodes(ListNode* head) {
        
        head=reverseList(head);
        
        stack<int> st;
        
        vector<int> sol;
        
        while(head!=NULL){
            
            if(st.size()==0){
                cout<<1<<endl;
                sol.push_back(0);
                st.push(head->val);
                head=head->next;
            }
            else{
                
               while( st.size() && st.top()<=head->val ){
                   st.pop();
               }
                
                if(st.size()==0) {
                    sol.push_back(0);
                    st.push(head->val);
                }
                else{
                    sol.push_back(st.top());
                    st.push(head->val);
                }
                head=head->next;
                
            }
            
        }
        
        reverse(sol.begin(),sol.end());
        return sol;
        
    }
};