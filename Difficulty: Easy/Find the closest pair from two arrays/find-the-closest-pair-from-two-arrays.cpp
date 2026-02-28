class Solution {
  public:
    vector<int> findClosestPair(vector<int> &a, vector<int> &b, int x) {
        int n = a.size();
        int m = b.size();
        
        int i = 0;
        int j = m - 1;
        
        long long bestDiff = LLONG_MAX;
        vector<int> ans(2);
        
        while (i < n && j >= 0) {
            long long sum = (long long)a[i] + b[j];
            long long diff = llabs(sum - x);
            
            if (diff < bestDiff) {
                bestDiff = diff;
                ans[0] = a[i];
                ans[1] = b[j];
            }
            
            if (sum > x) j--;
            else i++;
        }
        
        return ans;
    }
};