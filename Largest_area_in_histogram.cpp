class Solution {

private:

void previous_ele(int * arr,int n,vector<int>& heights){

stack<int> st;
stack<int> index;


for(int i =0;i<n;i++){

if(st.empty()){
  
    st.push(heights[i]);
    index.push(i);
    arr[i] = -1;
    continue;
}

else if(st.top() < heights[i]){
arr[i] = index.top();
st.push(heights[i]);
index.push(i);

}
else{
    while(st.top()>= heights[i]){
st.pop();

index.pop();
if(st.empty())
{
arr[i] = -1;
st.push(heights[i]);
index.push(i);
break;
}}

if(st.top() < heights[i]){
arr[i] = index.top();
st.push(heights[i]);
index.push(i);

}

}}}


void next_ele(int * brr,int n,vector<int>& heights){

stack<int> st;
stack<int> index;

for(int i =n-1;i>=0;i--){

if(st.empty()){
  
    st.push(heights[i]);
    index.push(i);
    brr[i] = -1;
    continue;
}

else if(st.top() < heights[i]){
brr[i] = index.top();
st.push(heights[i]);
index.push(i);
}
else{
     while(st.top()>= heights[i]){
st.pop();

index.pop();
if(st.empty())
{
brr[i] = -1;
st.push(heights[i]);
index.push(i);
break;
}}

if(st.top() < heights[i]){
brr[i] = index.top();
st.push(heights[i]);
index.push(i);
}

}}
}







public:
    int largestRectangleArea(vector<int>& heights) {
        

int n = heights.size();
int h;
int arr[n] ;
int brr[n];

previous_ele(arr,n,heights); 
next_ele(brr,n,heights);






int ans =0;



for(int i=0;i<n;i++){
if(arr[i] == -1){
    arr[i] = -1;
}
if(brr[i] == -1){
    brr[i] = n;
}
int area;
area = heights[i]*(brr[i] - arr[i] -1);



if(area>ans){
    ans = area;
}







}

return ans;


    }
};