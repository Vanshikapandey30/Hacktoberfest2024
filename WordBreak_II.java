import java.util.*;

class Solution {
    public List<String> ans;
    
    public void solve(int i, StringBuilder sentence, String givenString, Map<String, Boolean> doesExist) {
        if (i >= givenString.length()) {
            ans.add(sentence.toString());
            return;
        }
        for (int j = i + 1; j <= i + 10 && j <= givenString.length(); j++) {
            String word = givenString.substring(i, j);
            if (doesExist.containsKey(word)) {
                int lengthBeforeAppend = sentence.length();
                if (sentence.length() == 0) {
                    sentence.append(word);
                } else {
                    sentence.append(" ").append(word);
                }
                solve(j, sentence, givenString, doesExist);
                sentence.setLength(lengthBeforeAppend);
            }
        }
    }
    
    public List<String> wordBreak(String s, List<String> wordDict) {
        ans = new ArrayList<>();
        StringBuilder sentence = new StringBuilder();
        Map<String, Boolean> doesExist = new HashMap<>();
        for (String word : wordDict) {
            doesExist.put(word, true);
        }
        solve(0, sentence, s, doesExist);
        return ans;
    }
}
