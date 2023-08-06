class Solution {
    
    private:
    int timer = 0;
    
    void dfs(int node,int parent, vector<bool>&visited, vector<bool>&mark,int tin[],int low[],vector<int>adj[]){
        
        visited[node] = true;
      low[node] = tin[node] = timer;
      timer++;
      
      int child = 0;
      for(auto it : adj[node]){

          if(it == parent){
              continue;
          }
          
          if(visited[it]){
             low[node] = min(low[node], tin[it]); 
              
          }
          else if(!visited[it]){
              
           dfs(it,node,visited,mark,tin,low,adj);
              low[node] = min(low[node],low[it]);
              
              if(low[it] >= tin[node] && parent != -1){// it can't reach somewhere before this node
                  mark[node] = true;
              }
              
              if(parent == -1)
              child++;
          }
          
          
          
          
          
      }
        
        if(parent == -1 && child >1)
        mark[node] = true;
        
        
        
        
        
        
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int n = V;
        vector<bool>visited(n,false);
        int tin[n];
        int low[n];
        
        vector<bool>mark(n,false); //marks articulation points
        
        for(int i = 0; i < n; i++){
            
            if(!visited[i]){
                dfs(0,-1,visited,mark,tin,low,adj);
            }
            
            
            
        }
        
        vector<int>ans;
        
        for(int i = 0 ; i < n ; i++){
            
            if(mark[i] == true){
                ans.push_back(i);
            }
        }
        
        
        
        if(ans.size() == 0)
        ans.push_back(-1);
        
        return ans;
        
        
        
    }
};