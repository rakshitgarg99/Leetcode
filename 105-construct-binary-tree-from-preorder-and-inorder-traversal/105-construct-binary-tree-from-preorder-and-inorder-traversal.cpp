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
    
    
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        
        TreeNode* root = buildTree(preorder,0,preorder.size()-1,
                                   inorder,0,inorder.size()-1, inmap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder,int pstart, int pend,
                        vector<int>& inorder, int istart, int iend,
                        map<int,int> &inmap){
        
        if(pstart>pend or istart>iend) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pstart]);
        
        
        
        int inroot = inmap[root->val];
        int numleft= inroot-istart;
        
        
        
        root->left = buildTree(preorder,pstart+1,pstart+numleft,
                               inorder,istart,inroot-1, inmap);
        
        
        root->right = buildTree(preorder,pstart+numleft+1,pend,
                               inorder,inroot+1,iend, inmap);
        
        return root;
        
        
    }
    
    
};