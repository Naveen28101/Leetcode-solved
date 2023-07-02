//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n=s1.size();
        int m=s2.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            bool f=false;
            for(int j=0;j<n;j++){
                if(s1[(n+i+j)%n]!=s2[j]){
                    f=false;
                    break;
                }
                else{
                    f=true;
                }
            }
            if(f==true){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends