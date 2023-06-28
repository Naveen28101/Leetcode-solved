//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int f(int idx,int buy,int cap,int n,vector<int>& price,vector<vector<vector<int>>>& dp){
    if(idx==n || cap==0){
        return 0;
    }
    
    if(dp[idx][buy][cap]!= -1) return dp[idx][buy][cap];
    
    if(buy){
        return dp[idx][buy][cap]=max(-price[idx]+f(idx+1,0,cap,n,price,dp),
        f(idx+1,1,cap,n,price,dp));
    }
    else{
        return dp[idx][buy][cap]=max(price[idx]+f(idx+1,1,cap-1,n,price,dp),
        f(idx+1,0,cap,n,price,dp));
    }
}

int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,1,2,n,price,dp);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends