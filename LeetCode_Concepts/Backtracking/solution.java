package LeetCode_Concepts.Backtracking;

import java.util.StringTokenizer;

class Solution {
    public int lengthOfLastWord(String s) {
        s=s.trim();
        String str="";
        if(s==null||s.length()==0)
            return 0;
        StringTokenizer st=new StringTokenizer(s);
        int count=st.countTokens();
        for(int i=0;i<count-1;i++)
            str=st.nextToken();
        str=st.nextToken();
        return (int)(str.length());
    }
}