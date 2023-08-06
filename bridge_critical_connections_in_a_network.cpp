class Solution {
private:
int timer = 1;

private:

void dfs(int node,int parent,vector<bool>&visited,vector<int>adj[],int tin[],int low[],vector<vector<int>>&bridges){

visited[node] = true;

tin[node] = low[node] =timer;
timer++;

for(auto it : adj[node]){

if(it == parent){
    continue;
}

if(!visited[it]){

dfs(it,node,visited,adj,tin,low,bridges);
low[node] = min(low[node],low[it]); 
// can node --- it be a bridge

if(low[it] > tin[node])
bridges.push_back({node,it});

}

else if(visited[it]){

low[node] = min(low[node], low[it]);




}



}









} 

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        

vector<int>adj[n];

for(auto it : connections){

adj[it[0]].push_back(it[1]);
adj[it[1]].push_back(it[0]);

}

vector<bool>visited(n);
int tin[n]; // time in
int low[n];

vector<vector<int>>bridges;

int node = 0;
int parent = -1;
dfs(node,parent,visited,adj,tin,low,bridges);

return bridges;




    }
};