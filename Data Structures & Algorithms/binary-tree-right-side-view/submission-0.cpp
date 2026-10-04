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
    vector<int> rightSideView(TreeNode* root) {
        // right side elements
        // traverse level by level and the last node that is present ineach    //level is the right
        // side veiw in level order we need to get the last node
        vector<int> ans;
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
                level.push_back(node->val);
                

            }
            
            ans.push_back(level.back());
        }
        //now in level we have [[1],[2,3],[null,4,null,5]]
        return ans;
    }
};
