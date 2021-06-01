/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    TreeNode* start = NULL;
    TreeNode* end = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        midTravel(root);
        swap();
    }
    
    void midTravel(TreeNode* root) {
        if(!root) {
            return;
        }
        midTravel(root->left);
        compare(prev,root);
        prev = root;
        midTravel(root->right);
    }
    
    void compare(TreeNode* p,TreeNode* n) {
        if(p->val > n->val) {
            if(!start) {
                start = p;
            }
            end = n;
        }
    }
    
    void swap() {
        int buff = start->val;
        start->val = end->val;
        end->val = buff;
    }
};