// https://leetcode.com/problems/linked-list-components/submissions/

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
    int numComponents(ListNode* head, vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        for(auto el: nums){
            mp[el]++;
        }
        
        int ans=0;
        
        while(head!=NULL){
            
            if(mp.count(head->val)){
                
                ans++;
                while(head && mp.count(head->val)){
                    
                    head=head->next;
                }
                
            }else{
                head=head->next;
            }
            
        }
        return ans;
    }
};