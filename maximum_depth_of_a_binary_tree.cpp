class Solution {
public:
    int maxDepth(TreeNode* root) {
if(root == NULL)
return 0;

int d1 = maxDepth(root->left);

int d2 = maxDepth(root->right);

return max(d1,d2) + 1;





    }
};