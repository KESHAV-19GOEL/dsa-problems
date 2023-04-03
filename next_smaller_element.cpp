#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
stack<int> st;
if(n==0){

return ans;

}
  
st.push(arr[n-1]);
ans[n-1] = -1;

for(int i=n-2;i>=0;i--){

while(st.top()>=arr[i]){
st.pop();

if(st.empty()){
    st.push(arr[i]);
    ans[i] = -1;
   break;
}
continue;

}



if(st.top()<arr[i]){
ans[i] = st.top();

st.push(arr[i]);


}

}




    



return ans;







}