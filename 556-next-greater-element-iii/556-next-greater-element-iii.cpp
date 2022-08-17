#include <bits/stdc++.h>

class Solution {
public:
    int nextGreaterElement(int n) {
        
        int i,j;
        string num = to_string(n);
        int size = num.size();
        
        for(i=size-2;i>=0;i--){
            if(num[i]<num[i+1]){
                break;
            }
        }
        
        if(i<0) return -1;
        
        for(j=size-1;j>=0;j--){
            if(num[j]>num[i]){
                break;
            }
        }
        swap(num[i], num[j]);
        reverse(num.begin()+i+1, num.end());
        
        
        size_t ans = stoll(num);
        return ans == n || ans > INT_MAX ? -1 : ans;
         
        
    }
};