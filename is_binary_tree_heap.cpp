class Solution {
  public:
    bool isHeap(struct Node* tree) {
       
    vector<Node*>v;
    
    v.push_back(tree);
    int i = 0;
    
    
    while(i < v.size()){
        
        if(v[i]->left)
        v.push_back(v[i]->left);
        
        if(v[i]->right)
        v.push_back(v[i]->right);
        
        i++;
        
    }
       
       int n = v.size()/2 -1;
    for( i =0;i<n ;i++){
        if(v[i]->left == NULL || v[i]->right == NULL)
        return false;
        
        if(v[i]->left->data > v[i]->data || v[i]->right->data > v[i]->data)
        return false;
        
    }
     if(v[i]->left == NULL)
        return false;
        
        if((v[i]->left->data > v[i]->data) || (v[i]->right != NULL &&v[i]->right->data > v[i]->data))
        return false;
    
       return true;
       
       
    }
};