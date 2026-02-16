class Solution {
public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            int curHeight = (i == n ? 0 : arr[i]);
            
            while (!st.empty() && curHeight < arr[st.top()]) {
                int h = arr[st.top()];
                st.pop();
                
                int right = i;
                int left = st.empty() ? -1 : st.top();
                
                int width = right - left - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};
