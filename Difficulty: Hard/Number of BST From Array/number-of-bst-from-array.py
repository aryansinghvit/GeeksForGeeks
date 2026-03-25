class Solution:
    def countBSTs(self, arr):
        # Code here
        n = len(arr)
        
        if n < 2:
            return [1]
            
        mp = {arr[i]:i for i in range(n)}
        cnt = [-1]*n
        cnt[0] = 1
        arr.sort()
        
        for i in range(1, n):
            cnt[i] = self.cntBST(cnt, i-1)
        
        result = [-1]*n
        
        for i in range(n):
            result[mp[arr[i]]] = cnt[i] * cnt[n-1-i]
        
        return result
        
    def cntBST(self, cnt, k):
        
        curr = 0
        
        i = 0
        j = k
        
        while i <= k and j >= 0:
            curr += (cnt[i]*cnt[j])
            i+=1
            j-=1
        return curr