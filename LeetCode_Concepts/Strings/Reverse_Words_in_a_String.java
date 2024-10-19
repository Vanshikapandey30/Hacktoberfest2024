//For Problem Statement, click on this link: [Reverse Words in a String - LeetCode](https://leetcode.com/problems/reverse-words-in-a-string/description/)

//Solution
public class ReverseWordsInPlace {
    public static String reverseWords(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;

        //Reverse the entire character array
        reverse(arr, 0, n - 1);

        //Reverse each word in the reversed array
        int start = 0;
        for (int end = 0; end < n; end++) {
            if (arr[end] == ' ') {
                reverse(arr, start, end - 1);
                start = end + 1; // Move to the start of the next word
            }
        }
        // Reverse the last word
        reverse(arr, start, n - 1);

        //Remove extra spaces and build the final result
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (arr[i] != ' ') {
                if (result.length() > 0) {
                    result.append(" "); // Add space between words
                }
                while (i < n && arr[i] != ' ') {
                    result.append(arr[i++]);
                }
            }
        }
        
        return result.toString();
    }

    private static void reverse(char[] arr, int left, int right) {
        while (left < right) {
            char temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    public static void main(String[] args) {
        System.out.println(reverseWords("the sky is blue"));  
        System.out.println(reverseWords("  hello world  "));  
        System.out.println(reverseWords("a good   example"));  
    }
}

//Output
//1. blue is sky the
//2. world hello
//3. example good a

