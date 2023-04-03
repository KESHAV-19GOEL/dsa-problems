class Solution
{
    public:
    void flatten(Node *root)
    {
        Node* curr = root;
        Node* prev;
        
        
        if(root == NULL)
        return ;
        
        while(curr!= NULL){
            
            if(curr->left == NULL){
                
                
                curr = curr->right;
                
            }
            
            
        else{
                
            prev = curr->left;    
                
                while(prev->right != NULL){
                    prev = prev->right;
                    
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                
                curr = curr->right;
            
            
        }
            
            
            
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};