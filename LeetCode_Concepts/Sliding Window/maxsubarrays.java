import java.util.*;

class Solution {
    public List<Integer> maxOfSubarrays(List<Integer> arr, int n, int k) {
        Deque<Integer> deque = new LinkedList<>();
        int windowStart = 0, windowEnd = 0;
        List<Integer> result = new ArrayList<>();

        while (windowEnd < n) {
            while (!deque.isEmpty() && deque.peekLast() < arr.get(windowEnd)) {
                deque.pollLast();
            }

            deque.offerLast(arr.get(windowEnd));
            if (windowEnd - windowStart + 1 < k) {
                windowEnd++;
            }

            else if (windowEnd - windowStart + 1 == k) {
                result.add(deque.peekFirst());

                if (deque.peekFirst().equals(arr.get(windowStart))) {
                    deque.pollFirst();
                }

                windowStart++;
                windowEnd++;
            }
        }
        return result;
    }
}
