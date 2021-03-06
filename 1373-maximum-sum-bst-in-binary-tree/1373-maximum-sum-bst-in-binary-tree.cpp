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
     struct BSTNode {
        bool isBST;
        int mn;
        int mx;
        int sum;
    };
    BSTNode findMaxBST(TreeNode* node, int& res) {
        if (node != NULL) {
            BSTNode left = findMaxBST(node -> left, res);
            BSTNode right = findMaxBST(node -> right, res);
            bool isBST = (left.isBST and right.isBST and left.mx < node -> val and node -> val < right.mn);
            int sum = node -> val + left.sum + right.sum;
            if (isBST) res = max(res, sum);
            return { isBST, min(node -> val, left.mn), max(node -> val, right.mx) , sum};
        } else {
            return { true, INT_MAX, INT_MIN, 0};
        }
    }
    int maxSumBST(TreeNode* root) {
        int res = 0;
        findMaxBST(root, res);
        return res;
    }
};