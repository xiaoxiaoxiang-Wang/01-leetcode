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
    int maxSum = INT32_MIN;
    int maxPathSum(TreeNode* root) {
        int res = travel(root);
        return max(res,maxSum);
    }
    // 返回以此节点为终点的最大值
    int travel(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int maxLeft = travel(root->left);
        int maxRight = travel(root->right);
        int curr = root->val + max(maxLeft,0) + max(maxRight,0);
        maxSum = max(curr,maxSum);        
        return root->val+max(max(maxLeft,maxRight),0);
    }
};