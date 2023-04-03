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



bool flag = false;
bool check = true;
vector<vector<TreeNode* >> ans;
vector<vector<int >> answer;

if(root == NULL)
return answer;

TreeNode* node = root;


vector<TreeNode*> v;
vector<int> v1;

v.push_back(node);
v1.push_back(node->val);


ans.push_back(v);
answer.push_back(v1);

while(check){
check = false;
vector<TreeNode*> v;
vector<int> v1;
if(flag){
    flag = false;
int j = ans.size()-1;
int n = ans[j].size();
for(int i =n-1;i>=0;i--){

if(ans[j][i]->left != NULL){
v.push_back(ans[j][i]->left);
v1.push_back(ans[j][i]->left->val);
}
if(ans[j][i]->right != NULL){
v.push_back(ans[j][i]->right);
v1.push_back(ans[j][i]->right->val);
}

}}
else{

  flag = true;
int j = ans.size() -1;
int n = ans[j].size();
for(int i =n-1;i>=0;i--){

if(ans[j][i]->right != NULL)
{v.push_back(ans[j][i]->right);
v1.push_back(ans[j][i]->right->val);
}
if(ans[j][i]->left != NULL){
v.push_back(ans[j][i]->left);
v1.push_back(ans[j][i]->left->val);
}



}
}

if(v.size()){
check = true;
ans.push_back(v);
answer.push_back(v1);
}
}



return answer;

}




    
};