//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    long long calcu(vector<int>& piles,int m){
        long long total=0;
        for(int i=0;i<piles.size();i++){
            total+=ceil(double(piles[i])/double(m));
        }
        return total;
    }
    
  public:
    int Solve(int n, vector<int>& piles, int H) {
        // Code here
        int l=1;
        int h=*max_element(piles.begin(),piles.end());
        int ans=0;
        
        while(l<=h){
            int m=(l+h)/2;
            long long reqHrs=calcu(piles,m);
            if(reqHrs<=H){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        
        return ans;
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends