// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

void solution(vector<int> &nums, int i, int n, int sum, vector<int> &ans){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        
        solution(nums, i+1,n,sum,ans);//not included
        
        //included and move on
//         temp.push_back(nums[i]);
        solution(nums, i+1,n,sum+nums[i],ans);
        
    }
    vector<int> subsetSums(vector<int> num, int N)
    {
        // Write Your Code here
        vector<int> ans;
    int n=num.size();
    solution(num,0,n,0,ans);
    sort(ans.begin(), ans.end());
    return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends