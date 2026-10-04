/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //level order traversal using queue 
        //fifo
        //steps
        //1.create a queue then add the root to it
        //2.vector<vector<ans>>
        //3.whule(q!=nullptr) then we need to create a node for the q of //front then and then pop from queue and then add that node we created to //node->let to queuq and node of right to queue then add the node to level 
        
        TreeNode* temp=root;
        vector<vector<int>> ans;
        if(root==nullptr) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if((node->left)!=nullptr) q.push(node->left);
                if((node->right)!=nullptr) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);

           
            

        }

     return ans;   
    }
};
