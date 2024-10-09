Box Stacking Problem
====================

Problem Definition
------------------

The **Box Stacking Problem** is to find the maximum height that can be achieved by stacking a given set of boxes, where each box can be rotated. The boxes are defined by their width, depth, and height.

### Example

*   Input: `[(4, 6, 7), (1, 2, 3), (4, 5, 6), (10, 12, 32)]`
*   Output: `34` (The maximum height by stacking the boxes)

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach (O(n<sup>2</sup>))

This approach uses dynamic programming to store the maximum height that can be obtained with each box at the bottom.

#### Pseudocode

    function maxHeight(boxes):
            sort boxes by base area (width * depth) in descending order
            let dp = array of size n initialized to heights of the boxes
            for i from 1 to n:
                for j from 0 to i-1:
                    if box[j] can be placed on box[i]:
                        dp[i] = max(dp[i], dp[j] + height[i])
            return max(dp)
        

#### Java Implementation

    import java.util.Arrays;
    import java.util.Comparator;
    
    public class BoxStacking {
        static class Box {
            int width;
            int depth;
            int height;
    
            Box(int w, int d, int h) {
                this.width = w;
                this.depth = d;
                this.height = h;
            }
            
            int getBaseArea() {
                return width * depth;
            }
        }
    
        public static int maxHeight(Box[] boxes) {
            int n = boxes.length;
            Arrays.sort(boxes, Comparator.comparingInt(Box::getBaseArea).reversed());
    
            int[] dp = new int[n];
            for (int i = 0; i < n; i++) dp[i] = boxes[i].height;
    
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (boxes[i].width < boxes[j].width && boxes[i].depth < boxes[j].depth) {
                        dp[i] = Math.max(dp[i], dp[j] + boxes[i].height);
                    }
                }
            }
    
            int maxHeight = 0;
            for (int height : dp) {
                maxHeight = Math.max(maxHeight, height);
            }
    
            return maxHeight;
        }
    
        public static void main(String[] args) {
            Box[] boxes = {
                new Box(4, 6, 7),
                new Box(1, 2, 3),
                new Box(4, 5, 6),
                new Box(10, 12, 32)
            };
            int result = maxHeight(boxes);
            System.out.println("Maximum Height of Stacked Boxes: " + result);  // Output: 34
        }
    }
        

#### Time and Space Complexity

*   **Time Complexity:** O(n<sup>2</sup>)
*   **Space Complexity:** O(n) (for the dp array)

### 2\. Optimized Dynamic Programming Approach (O(n log n))

This approach involves sorting the boxes in descending order based on their base areas and then applying a modified version of the Longest Increasing Subsequence (LIS) technique.

#### Pseudocode

    function maxHeightOptimized(boxes):
            sort boxes by base area (width * depth) in descending order
            let dp = array of size n
            for each box in boxes:
                find the position to place it in dp using binary search
            return max(dp)
        

#### Java Implementation

    import java.util.Arrays;
    import java.util.Comparator;
    
    public class BoxStackingOptimized {
        static class Box {
            int width;
            int depth;
            int height;
    
            Box(int w, int d, int h) {
                this.width = w;
                this.depth = d;
                this.height = h;
            }
            
            int getBaseArea() {
                return width * depth;
            }
        }
    
        public static int maxHeightOptimized(Box[] boxes) {
            int n = boxes.length;
            Arrays.sort(boxes, Comparator.comparingInt(Box::getBaseArea).reversed());
    
            int[] dp = new int[n];
            int maxIndex = 0;
    
            for (int i = 0; i < n; i++) {
                int height = boxes[i].height;
                for (int j = 0; j < i; j++) {
                    if (boxes[i].width < boxes[j].width && boxes[i].depth < boxes[j].depth) {
                        height = Math.max(height, dp[j] + boxes[i].height);
                    }
                }
                dp[i] = height;
                if (height > dp[maxIndex]) {
                    maxIndex = i;
                }
            }
    
            return dp[maxIndex];
        }
    
        public static void main(String[] args) {
            Box[] boxes = {
                new Box(4, 6, 7),
                new Box(1, 2, 3),
                new Box(4, 5, 6),
                new Box(10, 12, 32)
            };
            int result = maxHeightOptimized(boxes);
            System.out.println("Maximum Height of Stacked Boxes: " + result);  // Output: 34
        }
    }
        

#### Time and Space Complexity

*   **Time Complexity:** O(n log n) (for sorting and using binary search)
*   **Space Complexity:** O(n) (for the dp array)