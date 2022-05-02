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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        ListNode* head=NULL;
        ListNode* list3;
        
        if(list1->val<list2->val){
            head=list1;
            list1=list1->next;
        }
        else{
            head=list2;
            list2=list2->next;
        }
        
        list3=head;
        while(list1!=NULL and list2!=NULL){
            if(list1->val<list2->val){
                list3->next=list1;
                list1=list1->next;
            }
            else{
                list3->next=list2;
                list2=list2->next;
            }
            list3=list3->next;
        }
        
        while(list1!=NULL){
            list3->next=list1;
            list1=list1->next;
            list3=list3->next;
        }
        
        while(list2!=NULL){
            list3->next=list2;
            list2=list2->next;
            list3=list3->next;
        }
        
        return head;
    }
};