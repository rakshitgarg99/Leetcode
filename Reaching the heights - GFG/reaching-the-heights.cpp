// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    
    if(n==1) return {a[0]};
    
    sort(a, a+n);
    
    
    int l=0, r=n-1;
    
    int cnt=0;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){cnt++;}
    }
    
    
    if(cnt==n-1) return {-1};
    vector<int> ans;
    while(r>l){
        ans.push_back(a[r]);
        ans.push_back(a[l]);
        l++;
        r--;
    }
    if(n%2!=0){ 
        
        ans.push_back(a[l]);
        
    }
    return ans;
}
