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
        /*
        ListNode* slow=head;
        int count=0;
        while(slow!=NULL){
            slow=slow->next;
            count++;
        }
        
        int target=count-n;
        
        ListNode* t1=head;
        ListNode* t2;
        
        if(target>=1){
        target--;
        while(target--){
            t1=t1->next;
        }
        t2=t1->next;

        t1->next=t1->next->next;
        delete(t2);
        }
        else{
            head=head->next;
            delete(t1);
        }
        
        return head;
        */
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast == NULL) return head->next; // edge case handled
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        
        ListNode*temp=slow->next;
        slow->next=slow->next->next;
        delete(temp);
        return head;
        
        
    }
};