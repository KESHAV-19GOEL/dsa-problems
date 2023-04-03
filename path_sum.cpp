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

void check(queue<int>q,long sum,int target,int & count){

if(q.empty())
return ;

while(!q.empty()){
while(sum != target && !q.empty() ){
sum -= q.front();
q.pop();

}

while(sum == target && !q.empty())
{count++;
sum -= q.front();
q.pop();

}
}


}


void solve(TreeNode* root, queue<int>q,int & count ,int targetSum, long sum){

if(root == NULL)
return;

q.push(root->val);
sum += root->val;

check(q,sum,targetSum,count);

solve(root->left,q,count,targetSum,sum);
solve(root->right,q,count,targetSum,sum);


}

public:
    int pathSum(TreeNode* root, int targetSum) {
        

queue<int>q;
int count = 0;
 long sum = 0;
solve(root,q,count,targetSum,sum);


return count;

    }
};