//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  private:
    int f(int i,int j,string p,string s,vector<vector<int>>& dp){
        if(i<0 && j<0) return 1;
        if(i<0 && j>=0) return 0;
        if(j<0 && i>=0){
            for(int ii=0;ii<=i;ii++){
                if(p[ii]!='*') return 0;
            }
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(p[i]==s[j] || p[i]=='?') return dp[i][j]=f(i-1,j-1,p,s,dp);
        else if(p[i]=='*'){
            return dp[i][j]=f(i-1,j,p,s,dp) | f(i,j-1,p,s,dp);
        }
        return 0;
    }
    
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str){
        int n=pattern.length();
        int m=str.length();
        vector<vector<int>> dp(n,vector<int>(m,-1)); 
        return f(n-1,m-1,pattern,str,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends