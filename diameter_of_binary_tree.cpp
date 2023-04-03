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

int max_depth(TreeNode* root,int& count/*,unordered_map<TreeNode* , int> & count*/){

if(root == NULL)
return 0;

int left = max_depth(root->left,count);

int right = max_depth(root->right,count);

//count[root] = left + right + 1;
int temp = left + right +1;
if(count< temp)
count = temp;

int ans = max(left,right) + 1 ;
return ans;

}


public:
    int diameterOfBinaryTree(TreeNode* root) {

//unordered_map<TreeNode* , int> count;

int count = 0;

max_depth(root,count);


return count-1;


    }
};