class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    
	    if(n ==1){
	    return arr[0];    
	    }
	    
	  int sum = 0;
	  
	  for(int i = 0; i< n; i++){
	      
	      sum += arr[i];
	      
	  }
	    
	   int k = sum/2;
	    
	    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
	    
	   for(int i = 0; i < n; i++){
	      
	   dp[i][0] = true;
	      
	  } 
	    
	    if(arr[0] <= k){
	        dp[0][arr[0]] = true;
	    }
	    
	    for(int i = 1 ; i< n; i++){
	        for(int target = 0; target <= k; target++){
	            
	            bool notTake = dp[i-1][target];
	            bool take = false;
	            
	            if(arr[i] <= target){
	                take = dp[i-1][target - arr[i]];
	            }
	            
	            dp[i][target] = take||notTake;
	            
	        }
	        
	    }
	    int nearest;
	    
	    for(int i =k; i >= 0 ; i--){
	        
	        if(dp[n-1][i]){
	           nearest = i ;
	           break;
	        }
	        
	    }
	    if(sum & 1){
	        
	    return 2*(k -nearest) +1;
	    }
	    
	    else
	    return 2*(k - nearest);
	} 
};