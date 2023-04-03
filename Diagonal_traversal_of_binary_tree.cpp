
void solve(Node *root , int &min,int count,unordered_map<int,queue<Node*>>&m){
    
   if(root == NULL)
   return;
   
   if(count<min)
   min = count;
   
   m[count].push(root);
   
   solve(root->left,min,count-1,m);
   
   solve(root->right,min,count,m);
   
    
}
vector<int> diagonal(Node *root)
{
   int count = 0;
   int min= 0;
   
   unordered_map<int,queue<Node*>>m;
   
   solve(root,min,count,m);
   
    vector<int>v;
    
    for(int i =0;i>=min;i--){
        
        while(!m[i].empty()){
            
            v.push_back(m[i].front()->data);
            m[i].pop();
        }
        
        
        
        
        
        
    }
   
   
   return v;
   
   
   
   
}