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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // If both are null, they match
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        // If one is null or values don't match, they aren't mirrors
        if (t1 == nullptr || t2 == nullptr || t1->val != t2->val) {
            return false;
        }
        
        // Check outer subtrees (t1->left with t2->right) 
        // and inner subtrees (t1->right with t2->left)
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};