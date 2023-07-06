//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    // Already solved in O(n) time complexity
	    // Solve it using binary search algorithm(O(log(n)))
	    int l=0,h=n-1;
        int ans=1e9;
        int idx=-1;
        
        while(l<=h){
            int m=(l+h)/2;
            if(arr[l]<=arr[m]){
                //ans=min(ans,arr[l]);
                if(arr[l]<ans){
                    ans=arr[l];
                    idx=l;
                }
                l=m+1;
            }
            else{
                //ans=min(ans,arr[m]);
                if(arr[m]<ans){
                    ans=arr[m];
                    idx=m;
                }
                h=m-1;
            }
        }
        return idx;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends