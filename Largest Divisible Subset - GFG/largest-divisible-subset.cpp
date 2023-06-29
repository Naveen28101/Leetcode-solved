//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        vector<int> dp(n,1),hash(n,0);
        int ans=-1,last=-1;
        
        for(int idx=0;idx<n;idx++){
            hash[idx]=idx;
            for(int prev=0;prev<idx;prev++){
                if(arr[idx]%arr[prev]==0 && 1+dp[prev]>dp[idx]){
                    dp[idx]=1+dp[prev];
                    hash[idx]=prev;
                }
            }
            if(ans<dp[idx]){
                ans=dp[idx];
                last=idx;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[last]);
        while(hash[last]!=last){
            last=hash[last];
            temp.push_back(arr[last]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends