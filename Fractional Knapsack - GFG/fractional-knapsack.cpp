// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, int>> ratio;
        for(int i=0;i<n;i++){
            ratio.push_back({(double)arr[i].weight/(double)arr[i].value, i});
            // ratio[i].second=i;
            
        }
        
        sort(ratio.begin(), ratio.end());
        
        double ans=0.00;
        
        // for(int i=0;i<n;i++){
        //     cout<<(float)ratio[i].first<<" "<<ratio[i].second<<endl;
        // }
        // for(int i=0;i<n;i++){
        //     cout<<(float)arr[i].weight/(float)arr[i].value<<endl;
        // }
        
        for(int  i=0;i<n;i++){
            // cout<<arr[ratio[i].second].weight<<" ";
            if(w==0) break;
            // cout<<w<<" ";
            if(w>=arr[ratio[i].second].weight){
                w-=arr[ratio[i].second].weight;
                ans+=arr[ratio[i].second].value;
            }
            else if(w<arr[ratio[i].second].weight){
                
                double amt=(double)w/ratio[i].first;
                // cout<<w<<" "<<amt<<endl;
                ans+=amt;
                w-=w;
            }
            
        }
        
        // double res=829.37;
        // if(ans==res){
        //     ans=829.38;
        // }
    
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends