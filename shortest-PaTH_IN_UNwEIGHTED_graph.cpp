#include<bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
unordered_map<int,list<int>>adj;
map<int,int> parent;
vector<int>ans;
vector<bool>visited;

for(int i = 0; i< m; i++){

adj[edges[i].first].push_back(edges[i].second);
adj[edges[i].second].push_back(edges[i].first);

}

for(int i = 0; i< n;i++){

visited.push_back(false);
//note this vector has 0 based indexing

}


queue<int>q;

q.push(s);


while(!q.empty()){

int temp = q.front();
q.pop();

visited[temp - 1] = true;

for(auto i : adj[temp]){

if(!visited[i-1]){

	q.push(i);
	parent[i] = temp;
	visited[i-1] = true;
	if(i == t){
		break;
	}
}

}

}

stack<int>st;
int curr = t;
while(curr != s){

st.push(curr);
curr = parent[curr];


}

st.push(curr);

while(!st.empty()){
	ans.push_back(st.top());
	st.pop();
}

return ans;


}
