class Solution
{
    private:
    
    void solve(Node* root,int sum, int len,int & maxlen,int &max_sum){
        
        if(root == NULL){
            if(len>maxlen){
                maxlen = len;
                max_sum = sum;
                
            }
            
            if(len == maxlen){
                
                max_sum = max(sum,max_sum);
                
                
            }
            
            return;
        }
        
        solve(root->left,sum+ root->data,len+1,maxlen,max_sum);
        
        solve(root->right,sum + root->data,len+1,maxlen,max_sum);
        
        
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum = 0;
        int len = 0;
        int maxlen = 0;
        int max_sum = 0;
        
        solve(root,sum,len,maxlen,max_sum);
        
        return max_sum;
        
        
        
    }
};