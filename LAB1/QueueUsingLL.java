package LAB1;


public class QueueUsingLL {
    private class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;   
            this.next = null;
        }
    }
    private Node front,rear;
    QueueUsingLL(){
        front = rear = null;
    }
    public void enqueue(int val){
        Node newNode = new Node(val);
        if(rear ==null){
            front= rear = newNode;
            return ;
        }
        rear.next = newNode;
        rear = newNode;
    }
    public int dequeue(){
        if(front==null){
            System.out.println("Queue is empty");
            return -1;
        }
        int val = front.data;
        front = front.next;
        if(front ==null){
            rear = null;
        }
        return val;
    }
    boolean isEmpty(){
        return front==null;
    }
    public int peek(){
       if(front==null){
            System.out.println("Queue is empty");
            return -1;
        } 
        return front.data;
    }
    public static void main(String[] args){
        QueueUsingLL queue = new QueueUsingLL();
        queue.enqueue(37);
        queue.enqueue(47);
        queue.enqueue(57);
        queue.enqueue(67);
        System.out.println("poped element:"+queue.dequeue());
        System.out.println("top element:"+queue.peek());
        System.out.println("is queue empty:"+queue.isEmpty());
    }
}
