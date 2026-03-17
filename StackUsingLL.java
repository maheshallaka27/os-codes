public class StackUsingLL{
    private class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;   
            this.next = null;
        }
    }
    Node top;
    StackUsingLL(){
        top = null;
    }
    public void push(int val){
        Node newNode = new Node(val);
        newNode.next = top;
        top = newNode;
    }
    public int pop(){
        if(top==null){
            System.out.println("stack underflow");
            return -1;
        }
        int val = top.data;
        top = top.next;
        return val;
    }
    public int peek(){
        if(top==null){
            System.out.println("stack is empty");
            return -1;
        }
        return top.data;
    }
    public boolean isEmpty(){
        return top==null;
    }

    public static void main(String[] args){
        StackUsingLL stack = new StackUsingLL();
        stack.push(10);
        stack.push(20);
        stack.push(30);
        System.out.println("top element:"+stack.peek());
        System.out.println("poped element:"+stack.pop());
        System.out.println("top element:"+stack.peek());
        System.out.println("is stack empty:"+stack.isEmpty());


    }
}