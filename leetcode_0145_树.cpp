/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        Traver(root,res);
        return res;
    }
    
    void Traver(TreeNode* root,vector<int>& res) {
        if(!root) {
            return;
        }
        Traver(root->left,res);
        Traver(root->right,res);
        res.push_back(root->val);
    }
};