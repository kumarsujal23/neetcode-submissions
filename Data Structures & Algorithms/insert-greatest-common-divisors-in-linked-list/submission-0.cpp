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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        ListNode* front=head->next;
        while(front!=nullptr)
        {
            int val=__gcd(temp->val,front->val);
            ListNode* n=new ListNode(val,front);
            temp->next=n;
            temp=front;
            front=front->next;
        }
        return head;
    }
};