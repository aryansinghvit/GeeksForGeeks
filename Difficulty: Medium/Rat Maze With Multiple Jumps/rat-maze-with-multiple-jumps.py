class Solution:
    
    def ratmaze(self,mat,i,j,ans):
        n=len(mat)
        ans[i][j]=1
        if i==n-1 and j==n-1:
            return True
        for k in range(1,mat[i][j]+1):
            if j+k<n and mat[i][j+k]!=0:
                if self.ratmaze(mat,i,j+k,ans):
                    return True
            if i+k<n and mat[i+k][j]!=0:
                if self.ratmaze(mat,i+k,j,ans):
                    return True
        ans[i][j]=0
        mat[i][j]=0
        return False

	def shortestDist(self, mat):
        n=len(mat)
        ans=[[0]*n for _ in range(n)]
        if mat[0][0]!=0:
            if self.ratmaze(mat,0,0,ans):
                return ans
        return [[-1]]