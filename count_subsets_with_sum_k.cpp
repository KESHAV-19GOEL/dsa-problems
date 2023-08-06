int findWays(vector<int>& arr, int k)
{
	
	int n = arr.size();


vector<vector<int>> dp(n,vector<int>(k+1,0));

for(int i = 0; i< n;i++){
	dp[i][0] = 1;
}

if(arr[0] <= k){
dp[0][arr[0]] = 1;}

for(int i = 1; i < n; i++){
for(int target = 0; target <= k ; target++){

int take = 0;
int notTake = dp[i-1][target];

if(arr[i]<= target){
	take = dp[i-1][target-arr[i]];
}



dp[i][target] = (take%(1000000000+7) + notTake%(1000000000+7))%(1000000000+7);



}

}

return dp[n-1][k];

}
