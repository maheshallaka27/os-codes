import java.util.concurrent.Semaphore;

class Buffer {
    private final int[] buffer;
    private int in = 0, out = 0, size;

    private final Semaphore mutex = new Semaphore(1);
    private final Semaphore empty;
    private final Semaphore full = new Semaphore(0);

    public Buffer(int size) {
        this.size = size;
        buffer = new int[size];
        empty = new Semaphore(size);
    }

    public void produce(int item) throws InterruptedException {
        empty.acquire();      // wait for empty slot
        mutex.acquire();      // enter critical section

        buffer[in] = item;
        System.out.println("Produced: " + item + " at " + in);
        in = (in + 1) % size;

        mutex.release();      // leave critical section
        full.release();       // increase filled slots
    }

    public void consume() throws InterruptedException {
        full.acquire();       // wait for filled slot
        mutex.acquire();      // enter critical section

        int item = buffer[out];
        System.out.println("Consumed: " + item + " from " + out);
        out = (out + 1) % size;

        mutex.release();      // leave critical section
        empty.release();      // increase empty slots
    }
}

class Producer extends Thread {
    Buffer buffer;

    Producer(Buffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        try {
            for (int i = 1; i <= 5; i++) {
                buffer.produce(i);
                Thread.sleep(500);
            }
        } catch (Exception e) {}
    }
}

class Consumer extends Thread {
    Buffer buffer;

    Consumer(Buffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        try {
            for (int i = 1; i <= 5; i++) {
                buffer.consume();
                Thread.sleep(800);
            }
        } catch (Exception e) {}
    }
}

public class Main {
    public static void main(String[] args) {
        Buffer buffer = new Buffer(3);

        Producer p = new Producer(buffer);
        Consumer c = new Consumer(buffer);

        p.start();
        c.start();
    }
}