//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& a, int key) {
        // Code here
        int l=0,h=n-1;
        
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]==key){
                return true;
            }
            
            if(a[l]==a[m] && a[m]==a[h]){
                l++;h--;
                continue;
            }
            
            if(a[l]<=a[m]){
                if(key>=a[l] && key<a[m]){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else{
                if(key>a[m] && key<=a[h]){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends