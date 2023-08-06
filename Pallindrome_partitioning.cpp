class Solution {

public:


void solve(string &s,int i, int j,vector<vector<string>>& ans,vector<string>& v){

if(i == s.size()){
   ans.push_back(v);
    return;
}

for(int k = i; k <= j ; k++){
    if(ispallindrome(s,i,k)){
  v.push_back(s.substr(i,k+1-i));
  solve(s,k+1,j,ans,v);
  v.pop_back();

    }


}


    
}
bool ispallindrome(string& s, int i , int j){

while(i <= j){
if(s[i] != s[j]){
    return false;
}
    i++;
     j--;

}
return true;



}

    vector<vector<string>> partition(string s) {

 vector<vector<string>> ans;
vector<string> v;
int n = s.length();

 solve( s,0,n-1,ans,v);

return ans;

        
    }
};