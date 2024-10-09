K-th Largest Element Problem
============================

Problem Statement
-----------------

The K-th largest element in an array is the element that would be in the K-th position if the array were sorted in descending order. Given an array of integers, the task is to find the K-th largest element.

Example
-------

Input: `nums = [3, 2, 1, 5, 6, 4], k = 2`

Output: `5` (The second largest element is 5.)

Approaches
----------

### 1\. Sorting Approach

Sort the array in descending order and return the K-th element.

    import java.util.Arrays;
    
    public class KthLargestElementSorting {
        public static void main(String[] args) {
            int[] nums = {3, 2, 1, 5, 6, 4};
            int k = 2;
            System.out.println(findKthLargest(nums, k));
        }
    
        public static int findKthLargest(int[] nums, int k) {
            Arrays.sort(nums);
            return nums[nums.length - k];
        }
    }
    

**Time Complexity:** O(N log N) due to sorting.

**Space Complexity:** O(1) if the sorting is done in-place.

### 2\. Min-Heap Approach

Use a min-heap of size K to keep track of the K largest elements. The root of the heap will be the K-th largest element.

    import java.util.PriorityQueue;
    
    public class KthLargestElementHeap {
        public static void main(String[] args) {
            int[] nums = {3, 2, 1, 5, 6, 4};
            int k = 2;
            System.out.println(findKthLargest(nums, k));
        }
    
        public static int findKthLargest(int[] nums, int k) {
            PriorityQueue minHeap = new PriorityQueue<>();
            for (int num : nums) {
                minHeap.offer(num);
                if (minHeap.size() > k) {
                    minHeap.poll();
                }
            }
            return minHeap.peek();
        }
    }
    

**Time Complexity:** O(N log K), where N is the number of elements in the array.

**Space Complexity:** O(K) for the heap storage.

### 3\. Quick Select Approach

This approach uses a partitioning technique similar to quicksort to find the K-th largest element in average O(N) time.

    import java.util.Random;
    
    public class KthLargestElementQuickSelect {
        public static void main(String[] args) {
            int[] nums = {3, 2, 1, 5, 6, 4};
            int k = 2;
            System.out.println(findKthLargest(nums, k));
        }
    
        public static int findKthLargest(int[] nums, int k) {
            return quickSelect(nums, 0, nums.length - 1, nums.length - k);
        }
    
        private static int quickSelect(int[] nums, int left, int right, int index) {
            if (left == right) {
                return nums[left];
            }
            
            int pivotIndex = partition(nums, left, right);
            if (index == pivotIndex) {
                return nums[pivotIndex];
            } else if (index < pivotIndex) {
                return quickSelect(nums, left, pivotIndex - 1, index);
            } else {
                return quickSelect(nums, pivotIndex + 1, right, index);
            }
        }
    
        private static int partition(int[] nums, int left, int right) {
            int pivot = nums[right];
            int i = left;
            for (int j = left; j < right; j++) {
                if (nums[j] < pivot) {
                    swap(nums, i, j);
                    i++;
                }
            }
            swap(nums, i, right);
            return i;
        }
    
        private static void swap(int[] nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    

**Time Complexity:** O(N) on average, O(N^2) in the worst case.

**Space Complexity:** O(1) for the partitioning.

Conclusion
----------

The K-th Largest Element problem can be solved using various approaches, each with different time and space complexities. The choice of approach depends on the specific constraints of the problem, such as the size of the input array and the value of K.