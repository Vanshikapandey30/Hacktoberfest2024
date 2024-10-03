// public package OpenSource.Hacktoberfest2024.DSA;

public class LinkedList {

    Node head;

    class Node{
        int data;
        Node next;

        Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    public void addfirst(int data){
        Node newnode = new Node(data);
        if(head == null){
            head = newnode;
            return;
        }
        newnode.next = head;
        head = newnode;
    }

    public void insertion(int data){
        Node newnode = new Node(data);
        if (head == null) {
            head = newnode;
            return;            
        }
        Node currNode = head;
        while(currNode.next != null){
            currNode = currNode.next;
        }
        currNode.next = newnode;
    }

    public void printlist(){
        if(head == null){
            System.out.println("the list is empty");
            return;
        }

        Node currNode = head;
        while (currNode != null) {
            System.out.println(currNode.data);  
            currNode = currNode.next;          
        }
        System.out.println("null");
    }

    public void deletefirst(){
        if(head == null){
            System.out.println("the list is empty");
            return;
        }
        head = head.next;
    }

    public void deletelast(){
        if (head == null) {
            System.out.println("the list is empty");
            return;
        }

        if (head.next == null) {
            System.out.println("there is only one element");
            return;
        }

        Node secondlast = head;
        while (secondlast.next.next != null) {
            secondlast = secondlast.next;
        }
        secondlast.next = null;
    }

    public void deleteatposition(int n){
        if (head == null || n < 1) {
            System.out.println("the list is empty");
            return;
        }

        if (n == 1) {
            head = head.next;
            return;            
        }

        Node currNode = head;
        for(int i = 1;i < n-1 && currNode != null; i++ ){
            currNode = currNode.next;
        }

        if (currNode == null && currNode.next == null) {
            System.out.println("position is out of bounds");
            return;
        }
        currNode.next = currNode.next.next;        
    }


    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insertion(1);
        list.insertion(2);
        list.printlist();

    }    
}