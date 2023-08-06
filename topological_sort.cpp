void solve(stack<int>&s,map<int,list<int>>&m1,map<int,bool>&visited,int current_element){

visited[current_element] = true;

for(auto i : m1[current_element]){

if(!visited[i])
solve(s,m1,visited,i);
}

s.push(current_element);

}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    

map<int,list<int>>m1;
stack<int>s;


for(int i =0 ; i< e;i++){
m1[edges[i][0]].push_back(edges[i][1]);

}

map<int,bool>visited;

for(int i =1 ; i<v ; i++){
visited[i] = false;

}

for (int i = 0; i < v; i++) {

if(!visited[i]){

solve(s,m1,visited,i);
}}

vector<int>ans;

while(!s.empty()){

ans.push_back(s.top());
s.pop();

}

return ans;


}