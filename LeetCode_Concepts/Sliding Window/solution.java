import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    public String minWindow(String s, String t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }

        // Dictionary to store the frequency of characters in `t`
        Map<Character, Integer> dictT = new HashMap<>();
        for (char c : t.toCharArray()) {
            dictT.put(c, dictT.getOrDefault(c, 0) + 1);
        }

        // Number of unique characters in `t` that must be present in the window
        int required = dictT.size();

        // Left and right pointer, and the count of characters in the current window matching `t`
        int l = 0, r = 0, formed = 0;

        // Dictionary to store character frequencies in the current window
        Map<Character, Integer> windowCounts = new HashMap<>();

        // Result to store the smallest window (length, left, right)
        int[] ans = {-1, 0, 0};

        // Expand the window with the right pointer
        while (r < s.length()) {
            char c = s.charAt(r);
            windowCounts.put(c, windowCounts.getOrDefault(c, 0) + 1);

            // If the current character is part of `t` and its count in the window matches `t`, update `formed`
            if (dictT.containsKey(c) && windowCounts.get(c).intValue() == dictT.get(c).intValue()) {
                formed++;
            }

            // Try to contract the window when all characters in `t` are included
            while (l <= r && formed == required) {
                c = s.charAt(l);

                // Update the smallest window found
                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                // Shrink the window from the left
                windowCounts.put(c, windowCounts.get(c) - 1);
                if (dictT.containsKey(c) && windowCounts.get(c) < dictT.get(c)) {
                    formed--;
                }

                l++;
            }

            // Expand the window from the right
            r++;
        }

        // Return the smallest window or an empty string if no valid window exists
        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter string s: ");
        String s = scanner.nextLine();
        System.out.print("Enter string t: ");
        String t = scanner.nextLine();

        Solution solution = new Solution();
        String result = solution.minWindow(s, t);
        System.out.println("Minimum window substring: " + result);
    }
}
