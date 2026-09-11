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
private:
    int maxDiameter = 0;

    int getDepth(TreeNode* node) {
        if (!node) return 0;

        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);

        // Update the maximum diameter found so far (sum of left and right subtree depths)
        maxDiameter = std::max(maxDiameter, leftDepth + rightDepth);

        // Return the depth of the current node
        return 1 + std::max(leftDepth, rightDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        getDepth(root);
        return maxDiameter;
    }
};