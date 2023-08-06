 #include<bits/stdc++.h>

 void solve( map<int,list<int>>&m1,map<int,bool> &visited,bool &ans,int current_element){
      
      
      
queue<int>q;
      q.push(current_element);

    while(!q.empty()){
 
 visited[q.front()] = true;
 int count = 0;

for(auto i : m1[q.front()]){

if(visited[i] == true){

count++;

if (count == 2) {
  ans = true;
  return;
}

continue;

}
else{

q.push(i);

}

} 
q.pop();
    }


                        
                                      
      
      }
 

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{

  
        map<int,list<int>>m1;
        map<int,bool> visited;
        bool ans = false;
        
         for(int i = 1;i<= n;i++){
            
            visited[i] =false;
        }
        
        for(int i =0;i<m;i++){
        
                
                m1[edges[i][0]].push_back(edges[i][1]);
            m1[edges[i][1]].push_back(edges[i][0]);
            
        }
        
        for(int i = 1;i<= n;i++){
        
        
        if(!visited[i]){
        /*
         for(int i = 1;i<= n;i++){
            
            visited[i] =false;
        }*/
        
        solve(m1,visited,ans,i);}
            
        }
        
      if(ans){
          string s = "Yes";
          return s;
      }
        
        string s1 = "No";

        return s1;
        




}
