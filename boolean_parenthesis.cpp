class Solution{
    private:
    
    int solve(string& S,int i,int j,bool istrue,vector<vector<vector<int>>>& dp){
       if(i > j){
           return 0;
       }
       
        if(i == j){
          if(istrue){
              return S[i] == 'T';
          }  
            if(!istrue){
                return S[i] == 'F';
            }
        }
        
        if(istrue && dp[i][j][1] != -1){
            return dp[i][j][1];
        }
        
        if(!istrue && dp[i][j][0] != -1){
            return dp[i][j][0];
        }
        
        
        
        int ans0 = 0;
        int ans1 = 0;
        int m = 1003;
        
        for(int k = i+1 ; k <j ; k += 2){
            int lt;
            if(dp[i][k-1][1] != -1){
                lt = dp[i][k-1][1];
            }
            else
            lt = solve(S,i,k-1,true,dp);
            
            int lf;
            if(dp[i][k-1][0] != -1){
                lf = dp[i][k-1][0];
            }
            else
            lf = solve(S,i,k-1,false,dp);
            
            int rt;
            if(dp[k+1][j][1] != -1){
                rt = dp[k+1][j][1];
            }
            else
            rt = solve(S,k+1,j,true,dp);
            
            int rf;
            if(dp[k+1][j][0] != -1){
                rf = dp[k+1][j][0];
            }
            else
            rf = solve(S,k+1,j,false,dp);
            
            
            if(S[k] == '&'){
                ans0 = ans0 + (lf*rt%m + rf*lt%m + rf*lf%m)%m;
                ans1 += (rt*lt)%m;
                
            ans0 =  ans0%m;
            ans1 =  ans1%m;
            }
            
            if(S[k] == '|'){
                ans1 += (lf*rt%m + rf*lt%m + rt*lt%m)%m;
                ans0 += (rf*lf)%m;
                
                            ans0 =  ans0%m;
            ans1 =  ans1%m;
            }
            
            if(S[k] == '^'){
                ans1 += (lt*rf%m + rt*lf%m)%m;
                ans0 += (rt*lt%m + lf*rf%m )%m;
                
                            ans0 =  ans0%m;
            ans1 =  ans1%m;
            }
            
            }
        dp[i][j][1] = ans1;
        dp[i][j][0] = ans0;
        
    if(istrue){
        return ans1;
    }    
        else
        return ans0;
        
        
    }
    
    
public:
    int countWays(int N, string S){
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        int ans = solve(S,0,S.size()-1,true,dp);
        return ans;
        
    }
};