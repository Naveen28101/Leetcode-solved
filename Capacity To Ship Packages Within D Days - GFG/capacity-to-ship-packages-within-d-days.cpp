//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    int maxi(int arr[],int n){
        int ma=-1;
        for(int i=0;i<n;i++){
            ma=max(ma,arr[i]);
        }
        return ma;
    }
    
    int sum(int arr[],int n){
        int s=0;
        for(int i=0;i<n;i++){
            s+=arr[i];
        }
        return s;
    }
    
    int calcu(int arr[],int m,int n){
        int day=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=m){
                sum+=arr[i];
            }
            else{
                day++;
                sum=0;
                sum+=arr[i];
            }
        }
        return day;
    }
    
  public:
    int leastWeightCapacity(int arr[], int n, int days) {
        // code here
        int l=maxi(arr,n);
        int h=sum(arr,n);
        
        while(l<=h){
            int m=(l+h)/2;
            int day=calcu(arr,m,n);
            if(day<=days){
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
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends