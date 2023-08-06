// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {

//    int sum = 0;
//    int n = nums.size();

//    for(int i = 0; i< n;i++){
// sum += nums[i];

//    }
   
// if((sum & 1) || n== 1){
//     return false;
// }

// sum /= 2;

//  vector<vector<bool>>dp(n,vector<bool>(sum+1,0));

// for(int i = 0; i<n;i++){

// dp[i][0]= true;
// }

// dp[0][nums[0]] = true;

// for(int index  = 1; index < n ; index++){
// for(int target = 1; target <= sum; target++){

// bool notTake = dp[index-1][target];
// bool take = false; // check for error

// if(nums[index] <= target){
//     take = dp[index-1][target - nums[index]];
// }

//  dp[index][target] = (take || notTake);



// }
// }



// return dp[n-1][sum];




//     }
// };

class Solution {
public:
bool solve(vector<int>nums , int n , int t)
{
    vector<int>curr(t+1,0);
    vector<int>next(t+1,0);
    curr[0]=1;
    next[0]=1;

    for (int index=n-1;index>=0;index--)
    {
        for(int target=0;target<=t;target++)
        {
            bool include =false;
            if(target-nums[index]>=0)
            {
                include= next[target-nums[index]];
            }
            bool exclude = next[target];
            curr[target]=include or exclude;
        }
        next =curr;
    }
    return next[t];

}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target=0;
        for(int i =0;i<n;i++)
        {
            target+=nums[i];
        }
        if(target%2==1)return 0;

        
        return solve(nums,n,target/2);
    }
};