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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        if(k==0){
            return head;
        }
        ListNode* temp=head;
        int i=1;
        while(temp->next!=NULL){
            temp=temp->next;
            i++;
        }
        if(k==i){
            return head;
        }
        if(k>i){
            k=k%i;
        }
        if(k==0){
            return head;
        }
        ListNode* temp1=head;
        for(int j=0;j<i-k-1;j++){
            temp1=temp1->next;
        }
        ListNode* mid=temp1->next;
        temp1->next=NULL;
        ListNode *temp2=mid;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=head;
        head=mid;
        return head;
    }
};