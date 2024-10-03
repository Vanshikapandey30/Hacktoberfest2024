import java.util.*;

public class Stack
{
    class MyStack
    {
        ArrayList<Integer> stack = new ArrayList<>();

        public void push(int data)
        {
            stack.add(data);
        }

        public Boolean isEmpty()
        {
            return stack.size() == 0;
        }

        public int peek()
        {
            if(isEmpty())
            {
                System.out.print("the list is empty");
                return -1;
            }
            System.out.println(stack.get(stack.size() - 1));            
            return stack.get(stack.size() - 1);
        }

        public int pop()
        {
            if(isEmpty())
            {
                System.out.print("the list is empty");
                return -1;
            }

            return stack.remove(stack.size() - 1);
        }

        public int size()
        {
            if(isEmpty())
            {
                System.out.print("the list is empty");
                return -1;
            }
            return stack.size();
        }

        public void clear()
        {
            stack.clear();
        }


    }



    public static void main(String[] args) 
    {
        Stack outerStack = new Stack();
        MyStack stack = outerStack.new MyStack();  
        stack.push(2);
        stack.peek();
    }
}
