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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c1=0,c2=0;
        ListNode* temp=l1;
        while(temp!=nullptr)
        {
            c1++;
            temp=temp->next;
        }
        temp=l2;
        while(temp!=nullptr)
        {
            c2++;
            temp=temp->next;
        }
        if(c2>c1)
        return addTwoNumbers(l2,l1);
        ListNode* temp2=l2;
        temp=l1;
        int carry=0;
        while(temp!=nullptr && temp2!=nullptr)
        {
            temp->val=temp->val+temp2->val+carry;
            carry=temp->val/10;
            temp->val=temp->val%10;
            temp=temp->next;
            temp2=temp2->next;
        }
        while(carry && temp!=nullptr)
        {
            temp->val=temp->val+carry;
            carry=temp->val/10;
            temp->val=temp->val%10;
            temp=temp->next;
        }
        if(carry && temp==nullptr)
        {
            temp=l1;
            while(temp->next!=nullptr)
            temp=temp->next;
            ListNode* p=new ListNode(carry);
            temp->next=p;
        }
        return l1;
    }
};
