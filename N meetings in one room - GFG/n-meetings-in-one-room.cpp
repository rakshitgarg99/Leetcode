// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution

{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct activity{
    int start;
    int end;
    int pos;
};

static bool compare(struct activity a,struct activity b){
    if(a.end<b.end) return true;
    else if(a.end>b.end) return false;
    else if(a.pos<b.pos) return true;
    else return false;
}
    
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        // int n=start.size();
    struct activity act[n];
    for(int i=0;i<n;i++){
        act[i].start=start[i];
        act[i].end=end[i];
        act[i].pos=i;
    }
    sort(act, act+n, compare);
    
    int ans=0;
    int i=0,j=1;
    ans++;
    for(;j<n;j++){
        if(act[i].end<act[j].start){
            i=j;
            ans++;
        }
    }
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends