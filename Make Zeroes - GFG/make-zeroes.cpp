//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> check=matrix;
        
        vector<pair<int,int>> v;
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check[i][j]==0){
                    //v.push_back({i,j});
                    int sum=0;
                    for(int k=0;k<4;k++){
                        int nrow=i+drow[k];
                        int ncol=j+dcol[k];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                            sum+=check[nrow][ncol];
                            matrix[nrow][ncol]=0;
                        }
                    }
                    matrix[i][j]=sum;
                }
            }
        }
        
        // for(auto it:v){
        //     int r=it.first;
        //     int c=it.second;
        //     for(int k=0;k<4;k++){
        //         int nrow=r+drow[k];
        //         int ncol=c+dcol[k];
        //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
        //             matrix[nrow][ncol]=0;
        //         }
        //     }
        // }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends