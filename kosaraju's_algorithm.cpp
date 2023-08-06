  void dfs(int node, vector<bool>&visited,vector<vector<int>>& adj,stack<int> &st ){
        
        visited[node] = true;
        
        for(auto it : adj[node]){
            
            if(!visited[it]){
                
                 dfs(it,visited,adj,st);
                
            }
            
        }
        
        st.push(node);
        
        
        
        
        
    }

    private:
    
      void dfsT(int node, vector<bool>&visited,vector<int> adjT[]){
        
        visited[node] = true;
        
        
        for(auto it : adjT[node]){
            
            if(!visited[it]){
                
                 dfsT(it,visited,adjT);
                
            }
            
        }
        
    
        
    }

    	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        vector<bool> visited(V,false);
        
        stack<int> st;
        
        for(int i = 0; i < V; i++){
            
            if(!visited[i]){
                
                dfs(i,visited,adj,st);
                        }
    
        }
        
        vector<int>adjT[V];
        
        for(int i = 0; i < V; i++){
            
            visited[i] = false;
            for(auto it : adj[i]){
                
                adjT[it].push_back(i);
                
            }
            
        }
        
        int ans = 0;
        
        while(!st.empty()){
            
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                ans++;
                dfsT(node,visited,adjT);
            }
            
            
        }
        
        
       return ans; 
    }