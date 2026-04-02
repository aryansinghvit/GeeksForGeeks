class Solution:
    
    def countWays(self, n, k):
        same_end, diff_end = 0, k
        for i in range(n - 1):
            same_end, diff_end = diff_end, (k - 1) * (same_end + diff_end)
        return same_end + diff_end
        #code here.
