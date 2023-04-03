#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
int n = q.size()/2;

stack<int> s1;
stack<int>s2;
for(int i=0; i<n;i++){

s1.push(q.front());

q.pop();
}

while(!s1.empty()){
    s2.push(s1.top());
    s1.pop();
}

while(!s2.empty()){

q.push(s2.top());
s2.pop();

q.push(q.front());
q.pop();




}







}
