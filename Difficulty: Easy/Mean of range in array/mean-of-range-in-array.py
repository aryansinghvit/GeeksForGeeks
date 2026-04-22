class Solution:
    def findMean(self, arr, queries):
        from itertools import accumulate, chain
        prefix_sums = list(chain([0], accumulate(arr)))
        return [(prefix_sums[j + 1] - prefix_sums[i]) // (j - i + 1) for i, j in queries]