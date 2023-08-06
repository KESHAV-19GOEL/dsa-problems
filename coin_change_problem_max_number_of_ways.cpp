#include<vector>
int solve(int index,int value,int *denominations ){

if(index == 0){
    if(value %(denominations[0]) == 0)
    return 1;

    else
    return 0;
}

int notTake = solve(index -1,value,denominations);

int take = 0;

if(denominations[index] <= value){
take = solve(index,value- denominations[index],denominations);

}

return take + notTake;


}

long countWaysToMakeChange(int *denominations, int n, int value)
{
// int answer = solve(n-1,value,denominations);
// return answer;

long k = value;

vector<vector<long>> dp(n,vector<long>(k+1,0));

for(int i = 0; i< n; i++){
    dp[i][0] = 1;
}
int temp = denominations[0];
while(temp<=k){
    dp[0][temp] = 1;
    temp += denominations[0];
}




for(int index = 1; index < n;index++){
for(long target = 0; target <= k; target++){

long notTake = dp[index-1][target];
long take = 0;
if(denominations[index] <= target){
    take = dp[index][target-denominations[index]];
}

dp[index][target] = take + notTake; 
}

}


return dp[n-1][k];

}