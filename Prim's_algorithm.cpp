#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    
map<int,list<pair<int,int>>>adj;
vector<int>mst(n+1);
vector<bool>visited(n+1);
vector<int>parent(n+1);
vector<pair<pair<int, int>, int>>answer;


for(int i = 0; i < m ; i++){

adj[g[i].first.first].push_back(make_pair(g[i].first.second,g[i].second));
adj[g[i].first.second].push_back(make_pair(g[i].first.first,g[i].second));
}

for(int i = 0; i <= n; i++){

mst[i] = INT_MAX;
visited[i] = false;
parent[i] = -1;

}

int min = INT_MAX;
int curr_node;

mst[1] = 0;
parent[1] = -1;


for(int i = 1;i<= n;i++){

// find min node
for(int j = 1; j <= n; j++){
  if (mst[j] < min && visited[j] == false) {

    min = mst[j];
    curr_node = j;
  }
}

visited[curr_node] = true;
// update distance of its adjacent nodes

for(auto k : adj[curr_node]){

if(mst[k.first] > k.second && visited[k.first] == false){
mst[k.first] = k.second;
parent[k.first] = curr_node;

}
}





min = INT_MAX;


}

for(int i = 2; i<= n ; i++){

// pair<int,int>p = make_pair(parent[i],i);
answer.push_back(make_pair(make_pair(parent[i],i),mst[i]));

// ans.push_back(a);
}



return answer;



}
