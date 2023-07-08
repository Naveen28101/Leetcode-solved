//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    long long calcu(vector<int>& nums,int m){
        long long total=0;
        for(auto it:nums){
            total+=ceil(double(it)/double(m));
        }
        return total;
    }
    
    
  public:
    int smallestDivisor(vector<int>& nums, int k) {
        // Write your code here.
        int n=nums.size();
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        
        while(l<=h){
            int m=(l+h)/2;
            long long division=calcu(nums,m);
            if(division<=k){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return l;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends