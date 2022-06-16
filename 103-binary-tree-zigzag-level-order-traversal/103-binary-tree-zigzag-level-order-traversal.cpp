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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        int flag=1;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
             for(int i=0;i<size;i++){
                 TreeNode* top = q.front();
                 q.pop();
                 
                 if(top->left!=NULL) q.push(top->left);
                 if(top->right!=NULL) q.push(top->right);
                 
                 temp.push_back(top->val);
             }
            
            if(flag%2==0){
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            flag++;
        }
        
        return ans;
    }
};