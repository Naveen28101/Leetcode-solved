//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int c=0;
 		int q=0;
 		int rs=0,re=n-1;
 		int cs=0,ce=m-1;
 		while(rs<=re && cs<=ce){
 		    if(q%4==0){
 		        for(int i=cs;i<=ce;i++){
 		            c++;
 		            if(c==k){
 		                return a[rs][i];
 		            }
 		        }
 		        rs++;
 		    }
 		    else if(q%4==1){
 		        for(int i=rs;i<=re;i++){
 		            c++;
 		            if(c==k){
 		                return a[i][ce];
 		            }
 		        }
 		        ce--;
 		    }
 		    else if(q%4==2){
 		        for(int i=ce;i>=cs;i--){
 		            c++;
 		            if(c==k){
 		                return a[re][i];
 		            }
 		        }
 		        re--;
 		    }
 		    else{
 		        for(int i=re;i>=rs;i--){
 		            c++;
 		            if(c==k){
 		                return a[i][cs];
 		            }
 		        }
 		        cs++;
 		    }
 		    q++;
 		}
 		return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends