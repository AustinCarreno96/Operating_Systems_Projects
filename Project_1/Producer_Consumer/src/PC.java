import java.util.LinkedList;

public class PC {
    private final LinkedList<Integer> list;
    int list_size = 5;

    PC(LinkedList<Integer> list) { this.list = list; }


    void produce() throws InterruptedException {
        int number = 1;

        while(true) {
            synchronized (this) {
                Thread.sleep(1000);
                if(list.size() == list_size) {
                    System.out.println("Producer Waiting.");
                    wait();
                } else {
                    // Adding to array
                    list.add(number);
                    System.out.println("Produced-" + number);
                    number++;
                }

                notifyAll();
            }// end synchronized
        }// end while loop
    }// end produce()


    void consume() throws InterruptedException {
        int index = 0;
        while(true) {
            synchronized (this) {
                Thread.sleep(1000);
                if(list.size() == 0) {
                    System.out.println("Consumer Waiting.");
                    wait();
                }// end while empty
                else {
                    int value = list.remove(index);
                    System.out.println("consumed-" + value);
                }

                notifyAll();
            }// end synchronized
        }// end while loop
    }// end consume()
}
