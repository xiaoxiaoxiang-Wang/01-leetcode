/* *
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    // 闭区间
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }
        int gap = 0;
        TreeNode *res = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) {
            return res;
        }
        while (preorder[preStart] != inorder[inStart + gap]) {
            gap++;
        }
        res->left = helper(preorder, inorder, preStart + 1, preStart + gap, inStart, inStart + gap - 1);
        res->right = helper(preorder, inorder, preStart + gap + 1, preEnd, inStart + gap + 1, inEnd);
        return res;
    }
};