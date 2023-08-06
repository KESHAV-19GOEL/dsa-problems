class Solution {
    public:

    int solve(int k, int n, vector<vector<int>>& dp){
 if(n == 0 || n == 1){
       return n;
   }
   
   if(k == 1){
       return n;
   }

if(dp[k][n] != -1 ){
return dp[k][n];
}


int mini = 10000000;
int a,b;

int l = 1, h = n;

while(l<= h){

int mid =(h+l)/2 ;

int left;
if(dp[k-1][mid-1] != -1){
    left = dp[k-1][mid-1];
}
left = solve(k-1,mid-1,dp);

int right;
if(dp[k][n - mid] != -1){
    right = dp[k][n - mid];
}
else
right = solve(k,n - mid,dp );

int temp = max(left,right) + 1;

mini = min(mini,temp);
if(left < right){
    l = mid + 1; 
}
else
h = mid - 1;


}

// for(int i = 1; i <= n; i++){
// if(dp[k][n-i] != -1){
//     a = dp[k][n-i];
// }
// else
// a = solve(k,n-i,dp);


// if(dp[k-1][i-1] != -1){
//     b = dp[k-1][i-1];
// }

// else
// b = solve(k-1,i-1,dp);

// int temp;
// temp = max(a,b) + 1;

// mini = min(temp,mini);






// }


return dp[k][n] = mini;










    



    }


    int superEggDrop(int k, int n) {
       vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
       
        int ans= solve(k,n,dp);
        return ans;
  }
};
