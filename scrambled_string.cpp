class Solution {
private:
bool solve(string s1, string s2,map<string,int>& m){
if(s1 == s2){
    return true;
}
if(s1.length() <= 1 || s1.length() != s2.length()){
    return false;
}
int n = s1.length();
// bool ans = false;

string s = s1;
s += s2;

if(m.find(s) != m.end()){
    return m[s];
}


for(int k = 1; k< n ; k++){

bool swapped = solve(s1.substr(0,k), s2.substr(n-k,k),m) && solve(s1.substr(k,n-k), s2.substr(0,n-k),m); 

bool unswapped = solve(s1.substr(0,k), s2.substr(0,k),m) && solve(s1.substr(k,n-k), s2.substr(k,n-k),m);

if(swapped || unswapped){
    return m[s] = true;
    
}

}

return m[s] = false;

}

public:
    bool isScramble(string s1, string s2) {
        
      map<string,int>m;
        bool ans = solve(s1,s2,m);

return ans;

        
    }
};