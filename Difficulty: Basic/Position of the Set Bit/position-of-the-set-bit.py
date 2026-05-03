class Solution:
    def findPosition(self, n):
        # code here 
        if n&(n-1) != 0:
            return -1
        return (n-1).bit_count()+1
 