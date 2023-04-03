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
private:

TreeNode* ans(TreeNode* root, TreeNode* p, TreeNode* q){


if(root==NULL)
{return NULL;
}

if(root == p)
return p;
if(root == q)
return q;

TreeNode* leftans = ans(root->left,p,q);

TreeNode* rightans = ans(root->right,p,q);

if(leftans == p && rightans == q)
return root;

if(leftans == q && rightans == p)
return root;

if(leftans != NULL && rightans == NULL)
return leftans;

if(leftans == NULL && rightans != NULL)
return rightans;
if(leftans == NULL && rightans == NULL)
return NULL;


return NULL;
}



public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
   map<TreeNode*,queue<TreeNode*>>m;

TreeNode* answer =  ans(root, p, q);
   

return answer;











    }
};