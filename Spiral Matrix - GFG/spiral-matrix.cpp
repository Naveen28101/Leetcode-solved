//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int y)
    {
        // Your code goes here
        int rs=0,re=n-1;
        int cs=0,ce=m-1;
        
        int x=0;
        int c=0;
        
        while(rs<=re && cs<=ce){
            if(x%4==0){
                for(int k=cs;k<=ce;k++){
                    c++;
                    if(c==y){
                        return a[rs][k];
                    }
                }
                rs++;
            }
            else if(x%4==1){
                for(int k=rs;k<=re;k++){
                    c++;
                    if(c==y){
                        return a[k][ce];
                    }
                }
                ce--;
            }
            else if(x%4==2){
                for(int k=ce;k>=cs;k--){
                    c++;
                    if(c==y){
                        return a[re][k];
                    }
                }
                re--;
            }
            else{
                for(int k=re;k>=rs;k--){
                    c++;
                    if(c==y){
                        return a[k][cs];
                    }
                }
                cs++;
            }
            x++;
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
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends