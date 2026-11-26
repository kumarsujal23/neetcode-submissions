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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        return {};
        vector<ListNode*> v;
        for(auto it:lists)
        {
            while(it!=nullptr)
            {  
                v.push_back(it);
                it=it->next;
            }
        }
        sort(v.begin(),v.end(),[](ListNode* a,ListNode* b){return a->val<b->val;});
        for(int i=0;i<v.size()-1;i++)
        {
            if(i+1<v.size())
            v[i]->next=v[i+1];
        }
        v[v.size()-1]->next=nullptr;
        return v[0];
    }
};
