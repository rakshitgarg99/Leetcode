// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=0;
        while(i<n){
            pq.push(arr[i]);
            i++;
        }
        
        long long a=0, b=0;
        while(!pq.empty()){
            a+=pq.top();
            a*=10;
            pq.pop();
            
            if(!pq.empty()){
            b+=pq.top();
            b*=10;
            pq.pop();
            }
        }
        return (a+b)/10;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends