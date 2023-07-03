//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int first=INT_MIN;
	    int second=INT_MIN;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]>first){
	            second=first;
	            first=arr[i];
	        }
	        else if(arr[i]>second && arr[i]!=first){
	            second=arr[i];
	        }
	    }
	    
	    if(second==INT_MIN) return -1;
	    return second;
	}
};

    //     int maxi=-1;
	   // for(int i=0;i<n;i++){
	   //     maxi=max(maxi,arr[i]);
	   // }
	   // int mini=INT_MAX;
	   // for(int i=0;i<n;i++){
	   //     if(maxi-arr[i]>0){
	   //         mini=min(mini,maxi-arr[i]);
	   //     }
	   // }
	   // if(mini==INT_MAX) return -1;
	   // return maxi-mini;


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends