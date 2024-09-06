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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> map;
        for(auto it:nums) map[it]=1;
        ListNode* temp=head;
        ListNode* prev=head;
        while(temp!=NULL){
            if(map.find(temp->val)==map.end()){
                prev=temp;
                temp=temp->next;
                continue;
            }
            else{
                if(temp==head){
                    head=head->next;
                    temp->next=NULL;
                    temp=head;
                    prev=head;
                }
                else{
                    prev->next=temp->next;
                    temp->next=NULL;
                    temp=prev->next;
                    // else temp=prev->next;
                    // prev=prev->next;
                }
            }
        }
        return head;
    }
};