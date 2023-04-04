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
private:

void inorder_bst(TreeNode* root,vector<int>& in){
if(root == NULL)
return;

inorder_bst(root->left,in);
in.push_back(root->val);
inorder_bst(root->right,in);

}

TreeNode* balance_bst(vector<int> & in,int s,int e){
if(s>e)
return NULL;

int mid = s+ (e-s)/2;

int m = in[mid];
TreeNode* node =  new TreeNode(m);

node->left = balance_bst(in,s,mid-1);

node->right = balance_bst(in,mid+1,e);

return node;

}

public:
    TreeNode* balanceBST(TreeNode* root) {
        
    vector<int> in;

inorder_bst(root,in);

int s= 0;
int e = in.size()- 1;

 TreeNode* ans = balance_bst(in,s,e);

return ans;


    }
};