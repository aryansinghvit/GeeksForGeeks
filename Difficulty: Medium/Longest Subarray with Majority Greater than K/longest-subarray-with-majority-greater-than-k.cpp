class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int> first;
        
        int prefix = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > k) prefix += 1;
            else prefix -= 1;
            
            if(prefix > 0)
                ans = i + 1;
            
            if(first.find(prefix) == first.end())
                first[prefix] = i;
            
            if(first.find(prefix - 1) != first.end())
                ans = max(ans, i - first[prefix - 1]);
        }
        
        return ans;
    }
};