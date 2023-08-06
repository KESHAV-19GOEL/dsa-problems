class Solution{
    
      public:
    void path(vector<vector<int>> m,vector<string>& ans ,int n,int x,int y,string s){
        
        
        if(x == n-1  && y == n-1){
            if(m[n-1][n-1] == 1)    
            ans.push_back(s);
            
            return;
            
            
            
        }
        
        
          if((y < n-1) && (m[y+1][x] == 1)){
            s.push_back('D');
            m[y][x] = 0;
           path(m,ans,n,x,y+1,s); 
             s.pop_back();
            
        }
        
          if((x >0) && (m[y][x-1] == 1)){
            s.push_back('L');
            m[y][x] = 0;
                        
           path(m,ans,n,x-1,y,s); 
              s.pop_back();
            
        }
        
         if((x <n-1) && (m[y][x+1] == 1)){
            s.push_back('R');
            m[y][x] = 0;
            
           path(m,ans,n,x+1,y,s); 
              s.pop_back();
        }
                                   
      
      
      if((y>0) && (m[y-1][x] == 1)){
            s.push_back('U');
            m[y][x] = 0;           
           path(m,ans,n,x,y-1,s); 
            
              s.pop_back();
        }
        
        
        
        
        
        
        
        
    }
    
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
    vector<string> ans;
    string s;
    
    if(m[0][0] == 0){
    return ans;}
        
        path(m,ans,n,0,0,s);
        
        return ans;
        
        
    }
};
