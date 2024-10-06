import java.util.*;
public class ReverseStringBYStack {

   public static String reverseStackStr(String str){
    Stack<Character> s= new Stack<>();
    int indx=0;
    while (indx < str.length()) {
        s.push(str.charAt(indx));
        indx++;
    }

    StringBuilder result= new StringBuilder("");

    while (!s.isEmpty()) {
        char curr=s.pop();
        result.append(curr);
    }

    return result.toString();

   }


    public static void main(String[] args) {
        String str="abc";

        System.out.println(reverseStackStr(str));

    }
    
}
