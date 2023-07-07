//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int tar=0;
        int sum=0;
        int maxLen=0;
        
        map<int,int> m;
        
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==tar){
                maxLen=max(maxLen,i+1);
            }
            
            int rem=sum-tar;
            
            if(m.find(rem)!=m.end()){
                maxLen=max(maxLen,i-m[rem]);
            }
            
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends