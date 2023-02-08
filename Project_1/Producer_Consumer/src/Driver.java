import java.util.ArrayList;
import java.util.LinkedList;

public class Driver {

    public static void main(String[] args) throws InterruptedException {
        LinkedList<Integer> list = new LinkedList<>();
        PC pc = new PC(list);

        Thread producer = new Thread(() -> {
            try { pc.produce(); }
            catch (InterruptedException e) { e.printStackTrace(); }
        });
        Thread consumer = new Thread(() -> {
            try { pc.consume(); }
            catch (InterruptedException e) { e.printStackTrace(); }
        });

        producer.start();
        consumer.start();

        producer.join();
        consumer.join();
    }
}// end Driver class
