class Solution {

TreeNode* construct_bst(vector<int>& preorder,TreeNode* max,TreeNode* min,int & i){

if(i >= preorder.size())
return NULL;
/*
TreeNode* node = new TreeNode(preorder[i]);

if(i == preorder.size()-1)
return node;


if(preorder[i+1]< node->val){
if(min != NULL && preorder[i+1] < min->val);

else
node->left = construct_bst(preorder,node,min,++i);

}

if(i >= preorder.size())
return NULL;

if(i == preorder.size()-1)
return node;


if(preorder[i+1] > node->val){
if(max != NULL && preorder[i+1] > max->val);

else
node->right = construct_bst(preorder,max,node,++i);

}
*/

if((max != NULL && preorder[i] > max->val) || (min!= NULL && preorder[i] < min->val))
return NULL;

TreeNode* node = new TreeNode(preorder[i++]);

node->left = construct_bst(preorder,node,min,i);
node->right = construct_bst(preorder,max,node,i);

return node;

}

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

TreeNode* min = NULL;
TreeNode* max = NULL;
int i  = 0;

TreeNode* answer = construct_bst(preorder,max,min,i);

return answer;


    }
};