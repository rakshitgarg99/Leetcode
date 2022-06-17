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
    
    int res=-1;
int val=0;
void inorder(TreeNode* root){
    if(root==NULL) return;
    
    
    inorder(root->left);
    val--;
    if(val==0){
        res=root->val;
        return;
    }
    inorder(root->right);
}
    int kthSmallest(TreeNode* root, int k) {
        val=k;
        res=-1;
        inorder(root);
        return res;
    }
};