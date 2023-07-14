//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    bool f(int i,int n,vector<int>& arr,int k){
        if(k==0) return true;
        if(i==n) return false;
        
        bool pick=false;
        if(k>=arr[i]){
            pick=f(i+1,n,arr,k-arr[i]);
            if(pick) return true;
        }
        bool notPick=f(i+1,n,arr,k);
        if(notPick) return true;
        
        return pick | notPick;
    }
    
    public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return f(0,n,arr,k);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends