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
    ListNode* reverselist(ListNode* head)
    {
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            ListNode* curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev=new ListNode();
        prev->next=head;
        for(int i=0;i<left-1;i++)
        prev=prev->next;
        ListNode* headlist=prev->next;
        ListNode* temp=headlist;
        for(int i=0;i<(right-left);i++)
          temp=temp->next;
        ListNode* next=temp->next;
        temp->next=nullptr;
        prev->next=reverselist(headlist);
        headlist->next=next;
        if(left==1)
        return prev->next;
        else
        return head;  
    }
};