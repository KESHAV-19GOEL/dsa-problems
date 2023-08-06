#include <bits/stdc++.h> 
int countPartitions(int n, int d, vector<int> &arr) {
    
// reutrn answer in 1000000000 modulo

int difference = d/2;
int sum = 0;
int mod = (int)(1e9+7);

for(int i = 0; i< n; i++){

sum += arr[i];
}
// return sum;

if(d> sum || d%2 != sum%2){
    return 0;
}


int k = sum/2;
// difference = difference/2;

vector<vector<int>> dp(n,vector<int>(k+1,0));

for(int i = 0 ; i< n; i++){
dp[i][0] = 1;
}

if(arr[0] <= k){
    dp[0][arr[0]] = 1;
}

for(int i =1 ; i< n; i++){
for(int target = 0; target <= k; target++){

int notTake = dp[i-1][target];
int take = 0;

if(arr[i] <= target){
    take = dp[i-1][target - arr[i]];
}

// dp[i][target] = (take%(1000000000 + 7) + notTake%(1000000000+7))%(1000000000+7);

dp[i][target] = (take + notTake)%mod;

}

}
int k1 = 1;
if(arr[0] == 0)
k1  = 2;

int answer =  (k1*dp[n-1][k- difference])%mod;

return answer;



}


