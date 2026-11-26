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
        int c=0;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            c++;
            temp=temp->next;
        }
        int k=c-n;
        if(k==0)
        {
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        else
        {
            temp=head;
            c=0;
            while(temp!=nullptr)
            {
                c++;
                if(c==k)
                {
                    ListNode* p=temp->next;
                    temp->next=temp->next->next;
                    delete p;
                    return head;
                }
                temp=temp->next;
            }
        }
        return head;
    }
};
