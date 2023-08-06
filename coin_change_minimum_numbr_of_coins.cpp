// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
// int k = amount;
// int n = coins.size();

// vector<vector<int>> dp(n,vector<int>(k+1,-1));


// int temp = coins[0];
// int multiple = 1;

// for(int i = 0; i < n; i++){
//     dp[i][0] = 0;
// }

// while(temp <= k){

//   dp[0][temp] = multiple;
//   multiple++;
//   temp += coins[0];  
// }

// for(int i = 1; i< n; i++){
// for(int target = 0; target <= k ; target++){

// int notTake = dp[i-1][target];

// int take = -1;

// if(coins[i] <= target){
//     if(dp[i][target - coins[i]] != -1){
//         take = 1+ dp[i][target-coins[i]];
//     }
// }

// if(take >=0 && notTake >=0){
//     dp[i][target] = min(take,notTake);
// }
// else if(take >=0){
//     dp[i][target] = take;
// }
// else{
//     dp[i][target] = notTake;
// }
// }

// }


// return dp[n-1][k];





//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
int k = amount;
int n = coins.size();

// vector<vector<int>> dp(n,vector<int>(k+1,-1));
vector<int> next(k+1,-1);
vector<int> curr(k+1,-1);

curr[0] = 0;
next[0]= 0;


int temp = coins[0];
int multiple = 1;


while(temp <= k){

 curr[temp] = multiple;
  multiple++;
  temp += coins[0];  
}

for(int i = 1; i< n; i++){
for(int target = 0; target <= k ; target++){

int notTake = curr[target];

int take = -1;

if(coins[i] <= target){
    if(next[target - coins[i]] != -1){
        take = 1+ next[target-coins[i]];
    }
}

if(take >=0 && notTake >=0){
    next[target] = min(take,notTake);
}
else if(take >=0){
    next[target] = take;
}
else{
    next[target] = notTake;
}

}

curr = next;
}


return curr[k];





    }
};