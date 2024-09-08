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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *temp=head;
        int i=0;
        while(temp!=NULL){
            temp=temp->next;
            i++;
        }
        vector<ListNode*> ans;
        if(i<=k){
            ListNode *temp=head;
            for(int j=0;j<i;j++){
                head=temp->next;
                temp->next=NULL;
                ans.push_back(temp);
                temp=head;
            }
            for(int j=0;j<k-i;j++){
                ans.push_back(NULL);
            }
            return ans;
        }
        else{
            ListNode *temp=head;
            for(int j=0;j<i%k;j++){
                for(int x=1;x<i/k+1;x++){
                    temp=temp->next;
                }
                ListNode *temp1=temp->next;
                temp->next=NULL;
                ans.push_back(head);
                temp=temp1;
                head=temp1;
            }
            for(int j=0;j<k-i%k;j++){
                for(int x=1;x<i/k;x++){
                    temp=temp->next;
                }
                ListNode *temp1=temp->next;
                temp->next=NULL;
                ans.push_back(head);
                temp=temp1;
                head=temp1;
            }
        }
        return ans;
    }
};