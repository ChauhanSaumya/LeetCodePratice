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
    int maxPathDown(TreeNode* root,int & ans)
    {
        if(root==NULL)return 0;
        int lp=max(0,maxPathDown(root->left,ans));
        int rp=max(0,maxPathDown(root->right,ans));
        ans=max(ans,lp+rp+root->val);
        return max(lp,rp)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPathDown(root,ans);
        return ans;
    }
};