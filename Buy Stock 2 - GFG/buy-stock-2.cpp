//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    // Memoization
    long long f(int idx,int buy,int n,vector<long long>&prices,vector<vector<int>>& dp){
        if(idx==n) return 0;
        
        if(dp[idx][buy]!= -1) return dp[idx][buy];
        
        if(buy){
            return dp[idx][buy]=max(-prices[idx]+f(idx+1,0,n,prices,dp),f(idx+1,1,n,prices,dp));
        }
        else return dp[idx][buy]=max(prices[idx]+f(idx+1,1,n,prices,dp),f(idx+1,0,n,prices,dp));
    }
    
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        // Memoization
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return f(0,1,n,prices,dp);
        
        // Tabulation:-
        
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[idx][buy]=max(-prices[idx]+dp[idx+1][0],dp[idx+1][1]);
                }
                else{
                    dp[idx][buy]=max(prices[idx]+dp[idx+1][1],dp[idx+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends