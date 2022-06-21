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
    
    TreeNode* solve(vector<int>& postorder, int pstart , int pend,
                    vector<int>&  inorder, int istart, int iend,
                    map<int, int> &inmap){
        
        if(pstart>pend or istart>iend) return NULL;
        
        TreeNode* root = new TreeNode(postorder[pend]);
        
        int inroot = inmap[postorder[pend]];
        int numleft = inroot-istart;
        
        root->left = solve(postorder,pstart,pstart+numleft-1,
                           inorder,istart,inroot-1,inmap);
        // pend-numleft,pend,
        root->right = solve(postorder,pstart+numleft,pend-1,
                           inorder,inroot+1,iend,inmap);
        
        // pstart+1,pend-numleft-1
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        
        // reverse(postorder.begin(), postorder.end());
        
        return solve(postorder,0,postorder.size()-1,
                     inorder,0,inorder.size()-1,
                     inmap);
    }
};