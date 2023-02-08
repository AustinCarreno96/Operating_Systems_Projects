import java.util.ArrayList;
import java.util.Arrays;

public class Main {


    public static void main(String[] args) throws InterruptedException {
        boolean flag = true;
        ArrayList<Integer> list = new ArrayList<>();

        Thread producer = new Thread(new Producer(list));
        Thread consumer = new Thread(new Consumer(list));

        producer.start();
        consumer.start();

        producer.join();
        consumer.join();
    }

    public static boolean checkIfEmpty(int[] arr) {
        for(int i : arr) {
            if(i >= 0) { return false; }
        }
        return true;
    }

    public static boolean getRandomBoolean() {
        return Math.random() > 0.5;
    }
}// end Main class
