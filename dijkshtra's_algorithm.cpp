#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
map<int,list<pair<int,int>>>adj;
vector<int>dist(vertices);
// contain distances
set<pair<int,int>>st;

for(int i = 0; i< edges; i++){
int u = vec[i][0];
int v = vec[i][1];
int w = vec[i][2];

adj[u].push_back(make_pair(v,w));
adj[v].push_back(make_pair(u,w));

}

for(int i = 0; i< vertices;i++){
    dist[i] = INT_MAX;
}

dist[source] = 0;


// first is the node second is the distance to reach there

st.insert(make_pair(source,0));

while(!st.empty()){

auto current1 = *st.begin();
st.erase(current1);

int current = current1.first;

for(auto neighbour : adj[current]){

  if (dist[current] + neighbour.second < dist[neighbour.first]) {

    auto record = st.find(make_pair(neighbour.first, dist[neighbour.first]));

    dist[neighbour.first] = dist[current] + neighbour.second;
    st.insert(make_pair(neighbour.first, dist[neighbour.first]));

    if (record != st.end()){
      st.erase(record);
  }
  
  
  
  }

}




}





return dist;


}
