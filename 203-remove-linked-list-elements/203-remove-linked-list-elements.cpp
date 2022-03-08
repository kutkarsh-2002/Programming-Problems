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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        ListNode* curr=head, *prev=NULL;
        
        while(curr!=NULL){
            if(head->val==val){
                head=head->next;
                curr=head;
            }
            else if(curr->val==val){
                curr=curr->next;
                prev->next=curr;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        
        return head;
    }
};