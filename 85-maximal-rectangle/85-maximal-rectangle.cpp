class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     
        int n=heights.size();
        vector<int> left(n), right(n);
        stack<int> st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            
            if(st.empty()) left[i]=0;
            else{
                left[i] = st.top()+1;
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            
            if(st.empty()) right[i]=n-1;
            else{
                right[i] = st.top()-1;
            }
            st.push(i);
        }
        
        int maxA=INT_MIN;
        
        for(int i=0;i<n;i++){
            maxA = max(maxA, heights[i]*(right[i]-left[i]+1));
        }
        return maxA;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxA=0, n=matrix.size(), m=matrix[0].size();
        vector<int> height(m,0);
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            int area = largestRectangleArea(height);
            maxA = max(maxA,area);
            
        }
        return maxA;
    }
};