class Solution {

public:
    int findTargetSumWays(vector<int>& nums, int target) {

if(target <0)
target *= -1;

int multiple =1;

if(nums[0] == 0){
multiple = 2;
}

int n = nums.size();
int sum = 0;

for(int i = 0; i< n;i++){
sum += nums[i];

}

if(target > sum || (target%2 != sum%2)){
    return 0;
}

int  k = sum/2;
int d = target/2;

vector<vector<int>> dp(n,vector<int>(k+1,0));

for(int i = 0; i< n;i++){
dp[i][0] = 1;
}

if(nums[0] <= k){
    dp[0][nums[0]] = 1;
}

for(int i = 1; i< n; i++){
for(int tar = 0; tar <= k; tar++){

int notTake = dp[i-1][tar];
int take = false;

if(nums[i] <= tar){
    take = dp[i-1][tar - nums[i]];
}

dp[i][tar] = take + notTake;

}

}


return multiple*dp[n-1][k - d];







    }
};