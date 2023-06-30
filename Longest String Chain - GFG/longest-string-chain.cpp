//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool check(string& s1,string& s2){
        if(s1.size()!=1+s2.size()) return false;
        int first=0,second=0;
        while(first<s1.size()){
            if(second<s2.size() && s1[first]==s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() && second==s2.size()) return true;
        return false;
    }
    
    static bool comp(string& s1,string& s2){
        return s1.size()<s2.size();
    }
    
  public:
    int longestChain(int n, vector<string>& words) {
        // Code here
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxi=1;
        
        for(int idx=0;idx<n;idx++){
            for(int prev=0;prev<idx;prev++){
                if(check(words[idx],words[prev]) && 1+dp[prev]>dp[idx]){
                    dp[idx]=1+dp[prev];
                }
            }
            if(maxi<dp[idx]){
                maxi=dp[idx];
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends