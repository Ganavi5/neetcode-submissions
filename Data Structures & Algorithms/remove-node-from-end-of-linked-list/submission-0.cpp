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
        vector<ListNode*> v;
        ListNode* t=head;
        while(t){
            v.push_back(t);
            t=t->next;
        }
        int x=v.size()-n;
        v.erase(v.begin()+x);
        if(x==0) return head->next;

        for(int i=1;i<v.size();i++){ 

            v[i-1]->next=v[i];
        }
        v[v.size()-1]->next=nullptr;
        head=v[0];
        return head;


        
    }
};
