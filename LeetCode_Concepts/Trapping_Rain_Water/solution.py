from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:

        count = 0

        leftmax = -1
        rightmax = -1

        leftMax = [-1] * len(height)
        rightMax = [-1] * len(height)

        for i in range(len(height)):
            if height[i] > leftmax:
                leftmax = height[i]
            leftMax[i] = leftmax

            if height[-1* (i+1)] > rightmax:
                rightmax = height[-1* (i+1)]
            rightMax[-1* (i+1)] = rightmax


        for i in range(1, len(height)):
            count += max( min( rightMax[i], leftMax[i] ) - height[i], 0)

        return count


solution = Solution()

heights = list(map(int, input("Enter the heights of the buildings : ").split()))

print(solution.trap(height=heights))
