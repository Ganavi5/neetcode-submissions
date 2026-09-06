/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        vector<Node*> v;
        vector<Node*> r;
        vector<Node*> e;
        Node* f = head;
        while (f) {
            e.push_back(f);
            v.push_back(new Node(f->val));
            r.push_back(f->random);
            f = f->next;
        }
        if (v.size() == 0) return head;
        for (int i = 1; i < v.size(); i++) {
            v[i - 1]->next = v[i];
        }
        v[v.size() - 1]->next = nullptr;

        for (int i = 0; i < v.size(); i++) {
            if (r[i] == nullptr) {
                v[i]->random = nullptr;

            } else {
                for (int j = 0; j < e.size(); j++) {
                    if (r[i] == e[j]) {
                        v[i]->random = v[j];
                        break;
                    }
                }
            }
        }

      
        return v[0];
    }
};
