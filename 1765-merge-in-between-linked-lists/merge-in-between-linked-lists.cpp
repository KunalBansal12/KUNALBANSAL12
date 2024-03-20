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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ll=list1;
        // ListNode* lr=list1;
        ListNode* rl=list1;
        // ListNode* rr=list1;
        ListNode* temp=list1;
        int i=1;
        while(i<=b+1){
            if(i==a){
                ll=temp;
            }
            if(i==b+1) rl=temp->next;
            temp=temp->next;
            i++;
        }
        temp=list2;
        while(temp->next!=NULL) temp=temp->next;
        ll->next=list2;
        temp->next=rl;
        return list1;
    }
};