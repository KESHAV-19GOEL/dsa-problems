class Solution{   
/*private:

bool f(int index, int target,vector<int>&arr){

if(target ==0 ){
return true;
}

if(index == 0){
    
    return target == arr[0];
}

bool take = false;
bool notTake = f(index -1 ,target,arr);


if(arr[index] <= target)
take = f(index -1 ,target - arr[index],arr) ;

return take||notTake;


}*/
public:
    bool isSubsetSum(vector<int>arr, int sum){
 
 int n = arr.size();
 int k = sum;
 
/* return f(n-1,k,arr);*/
 
 vector<vector<bool>>dp(n,vector<bool>(k+1,0));

for(int i = 0;i< n;i++){
    dp[i][0] = true;
} 
 
 dp[0][arr[0]] = true;
 
 for(int i = 1; i< n ; i++){
    for(int target = 1; target <= k;target++){
        
        bool take = false;
        if(arr[i] <= target){
            take = dp[i-1][target-arr[i]];
        }
        
        bool  notTake = dp[i-1][target];
       
        dp[i][target] = take || notTake; 
        
    }
     
 }
 
 
 
 return dp[n-1][k];
    
    }
};