class Solution {
    
    private:
    
    void solve(Node* root,  unordered_map<int,queue<int>>& m,int & max,int & min){
        
        if(root == NULL)
        return;
        Node* Root = root;
        queue<Node*> q;
        
        q.push(Root);
        q.push(NULL);
        
        m[0].push(q.front()->data);
        root->data = 0;

        // count and m update

        
        
        while(!q.empty()){
            if(q.front() == NULL){
                
                q.pop();
                if(!q.empty())
                q.push(NULL);
        continue;
            }
            
            
            
            if(q.front()->left !=NULL){
                q.push(q.front()->left);
                
                
              int d = q.back()->data;                    
                q.back()->data = q.front()->data - 1;
                m[q.back()->data].push(d);
        
        
        if(q.back()->data<min)
        min = q.back()->data;
                
            }
            
             if(q.front()->right != NULL){
                q.push(q.front()->right);
                int d = q.back()->data;   
                
                q.back()->data = q.front()->data+ 1;
        
         m[q.back()->data].push(d);
        
         if(q.back()->data>max)
        max = q.back()->data;
                
             }
            q.pop();
        }
        
        
        
        
        
        
        
        
        
    }
    
    
  public:
    vector <int> bottomView(Node *root) {
        
        unordered_map<int,queue<int>>m;
        int max= 0;
        int min = 0;
        
        solve(root,m,max,min);
               
               vector <int> v;
               
               for(int i = min;i<= max;i++){
                   v.push_back(m[i].back());
                   
               }
        
        return v;
    }
};