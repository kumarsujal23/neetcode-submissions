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
        if(head==nullptr || head->next==nullptr)
        return head;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr ||  head->next==nullptr)
        return head;
        ListNode* temp=head;
       int c=0;
       vector<ListNode*> res;
       ListNode* temp2=head;
        while(temp!=nullptr)
        {
            c++;
            if(c==k)
            {
                ListNode* node=temp->next;
                temp->next=nullptr;
                ListNode* newhead=reverselist(temp2);
                res.push_back(newhead);
                // while(newhead->next!=nullptr)
                // newhead=newhead->next;
                res.push_back(temp2);
                temp=node;
                temp2=node;
                c=0;
            }
            else
            temp=temp->next;
        }
        for(int i=1;i<res.size();i+=2)
        {
            if(i+1<res.size())
            res[i]->next=res[i+1];
        }
        if(c>0)
        res[res.size()-1]->next=temp2;
        return res[0];
    }
};
