import java.util.*;
public class PushAtBottomStack {
    public static void pushAtBottomStack(int data, Stack<Integer> s){

        if (s.isEmpty()) { // 2 then stack is empty
            s.push(data); // 3 then add new data
            return;
        }
        int top = s.pop();// fist by using the recursion function to pop all the element
        pushAtBottomStack(data, s); // 4 then add the data 
        s.push(top); // 5 then  push all the the element with is pop at first 

    }

    public static void reverseStack(Stack<Integer> s){
        if (s.isEmpty()) {
            return;
        }
        int top=s.pop();
        reverseStack(s);
        pushAtBottomStack(top, s);
    }

    public static void main(String[] args) {
        Stack<Integer> s= new Stack<>();
        s.push(1);
        s.push(2);
        s.push(3);

        // pushAtBottomStack(4, s); // output: 3 2 1 4
        reverseStack(s); // output is: 1 2 3
        while (!s.isEmpty()) {
            System.out.println(s.peek());
            s.pop();
        }
    }
}
