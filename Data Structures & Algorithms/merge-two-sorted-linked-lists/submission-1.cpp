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
        if(list1==NULL && list2==NULL)
        return NULL;
        else if(list1==NULL)
        return list2;
        else if(list2==NULL)
        return list1;

        ListNode* mergeList=new ListNode();
        ListNode* temp=mergeList;
        while(list1!=NULL && list2!=NULL)
        {
            ListNode* temp2=new ListNode();
            if(list1->val>list2->val)
            {
                temp->val=list2->val;
                list2=list2->next;
            }
            else
            {
               temp->val=list1->val;
               list1=list1->next; 
            }
            temp->next=temp2;
            temp=temp2;
        }
        while(list1!=NULL)
        {
            ListNode* temp2=new ListNode();
            temp->val=list1->val;
            temp->next=temp2;
            list1=list1->next;
            temp=temp2;
        }
        while(list2!=NULL)
        {
            ListNode* temp2=new ListNode();
            temp->val=list2->val;
            temp->next=temp2;
            list2=list2->next;
            temp=temp2;
        }
        temp=mergeList;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        return mergeList;
    }
};
