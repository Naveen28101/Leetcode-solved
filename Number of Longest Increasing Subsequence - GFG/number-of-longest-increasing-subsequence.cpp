//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&nums) {
        // Code here
        vector<int> dp(n,1),ct(n,1);
        int maxi=1;
        
        for(int idx=0;idx<n;idx++){
            for(int prev=0;prev<idx;prev++){
                if(nums[idx]>nums[prev] && 1+dp[prev]>dp[idx]){
                    dp[idx]=1+dp[prev];
                    ct[idx]=ct[prev];
                }
                else if(nums[idx]>nums[prev] && 1+dp[prev]==dp[idx]){
                    ct[idx]+=ct[prev];
                }
            }
            maxi=max(maxi,dp[idx]);
        }
        
        int c=0;
        for(int i=0;i<n;i++){
            if(maxi==dp[i]){
                c+=ct[i];
            }
        }
        
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends