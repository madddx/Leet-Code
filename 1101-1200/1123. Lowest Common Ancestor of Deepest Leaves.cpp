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
  pair<TreeNode*,int> f(TreeNode* root){
     if(!root)
       return {NULL,0};
     auto left=f(root->left);
     auto right=f(root->right);
     if(left.second>right.second)
       return {left.first,left.second+1};
    if(right.second>left.second)
      return {right.first,right.second+1};
    return {root,left.second+1}; 
     
  }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto ans=f(root);
    return ans.first;

    }
};
