
import java.util.*;
public class NextGreaterEleStack {


    public static void main(String[] args) {
        int arr[]={5, 3, 8, 2, 1, 0}; // anather array{6, 8, 0, 1,3}
        Stack<Integer> s= new Stack<>();
        int nextgrater[]= new int[arr.length];

        for(int i=arr.length-1; i>=0; i--){

            while (!s.isEmpty() && arr[s.peek()] <= arr[i]) {
                s.pop();
            }

            if (s.isEmpty()) {
                nextgrater[i]= -1;
            }else{
                nextgrater[i] = arr[s.peek()];

            }
            s.push(i);
        }

        for(int i=0; i<nextgrater.length; i++){
            System.out.print(nextgrater[i]+" ");
        }
        System.out.println();
    }

    // Grater Next right // next Smaller right  while (!s.isEmpty() && arr[s.peek()] => arr[i]) 
    // Grater Next Left // next Smaller left   for(int i=0; i<arr.length; i++) while (!s.isEmpty() && arr[s.peek()] => arr[i])
    
    
}
