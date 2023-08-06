class Solution{
    private:
    
    int f(int index,int N,int price[]){
        
        if(index ==0){
            return N*price[0];
            }
            
        int notTake = 0 + f(index-1,N,price);
        
        int take = INT_MIN;
        // index +1 represent the rod length
        if(index < N){
        take = price[index] + f(index,N - index-1,price);
        }
        
        return max(take,notTake);
                                                         
        
    }
  public:
    int cutRod(int price[], int n) {
        
        // return f(n-1,n,price);
        
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        
        for(int i = 0; i<= n; i++){
            dp[0][i] = i*price[0];
        }
        
        for(int index = 1; index<n; index++){
            for(int N = 0; N <= n; N++){
                
                int notTake = 0+ dp[index-1][N];
                int take = INT_MIN;
                
                if(index <N){
                    take = price[index] + dp[index][N-index-1];
                }
                
                dp[index][N] = max(take,notTake);
                
                
            }
            
        }
        
        
        return dp[n-1][n];
        
        
        
        
    }
};