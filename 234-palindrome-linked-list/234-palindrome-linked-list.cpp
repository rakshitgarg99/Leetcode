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
    
    ListNode* reverse(ListNode* head){
        
        ListNode* curr=head;
        ListNode* dummy=NULL;
        ListNode* ahead=NULL;
        
        while(curr!=NULL){
            ahead=curr->next;
            curr->next=dummy;
            dummy=curr;
            curr=ahead;
        }
        
        return dummy;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return true;
        }
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
       
        slow->next=reverse(slow->next);
        slow=slow->next;
        
        // ListNode* temp=head;
        while(slow!=NULL){
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        
        return true;
    }
};