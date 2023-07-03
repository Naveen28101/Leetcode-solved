//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int n=str.length();
        int sign=1,base=0,i=0;
        
        if(str[i]=='+' || str[i]=='-'){
            sign=1-2*(str[i++]=='-');
        }
        
        while(i<n){
            if(str[i]>='0' && str[i]<='9'){
                if(base>INT_MAX/10 || (base==INT_MAX/10 && str[i]-'0'>7)){
                    if(sign==1) return INT_MAX;
                    else return INT_MIN;
                }
                else{
                    base=base*10+str[i]-'0';
                }
            }
            else{
                    return -1;
            }
            i++;
        }
        return base*sign;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends