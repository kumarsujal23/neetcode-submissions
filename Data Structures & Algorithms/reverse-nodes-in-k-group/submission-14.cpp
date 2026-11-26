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
ListNode* reverselist(ListNode* head)
{
    ListNode* prev=nullptr;
    ListNode* temp=head;
    while(temp!=nullptr)
    {
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevtail=nullptr;
        ListNode* temp=head;
        ListNode* temp2=head;
        ListNode* newhead=nullptr;
        int c=0;
        while(temp!=nullptr)
        {
            c++;
            if(c==k)
            {
                ListNode* nextnode=temp->next;
                temp->next=nullptr;
                ListNode* newh=reverselist(temp2);
                if(prevtail!=nullptr)
                prevtail->next=newh;
                if(newhead==nullptr)
                newhead=newh;
                prevtail=temp2;
                temp=nextnode;
                temp2=nextnode;
                c=0;

            }
            else
            temp=temp->next;
        }
        if(c>0)
        prevtail->next=temp2;
        return newhead;
    }
};
