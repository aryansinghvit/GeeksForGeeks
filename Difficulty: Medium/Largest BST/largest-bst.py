class Solution:
    def largestBst(self, root):
        
        self.maxSize = 0
        
        def solve(node):
            if not node:
                return (float('inf'), float('-inf'), 0)
            
            left = solve(node.left)
            right = solve(node.right)
            
            # Check if current subtree is BST
            if left[1] < node.data < right[0]:
                size = left[2] + right[2] + 1
                self.maxSize = max(self.maxSize, size)
                
                # return (min, max, size)
                return (min(left[0], node.data),
                        max(right[1], node.data),
                        size)
            
            # If not BST
            return (float('-inf'), float('inf'), 0)
        
        solve(root)
        return self.maxSize

