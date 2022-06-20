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
    
    
    void solve(TreeNode* root, int level, int&ans){
        if(!root) return;
        
        ans=max(ans,level);
        solve(root->left,level+1,ans);
        solve(root->right,level+1,ans);
    }
    int maxDepth(TreeNode* root) {
        int ans=0;
        solve(root,1,ans);
        return ans;
    }
};