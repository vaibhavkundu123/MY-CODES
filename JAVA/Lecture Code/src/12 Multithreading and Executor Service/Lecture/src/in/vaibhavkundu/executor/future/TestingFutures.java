package in.vaibhavkundu.executor.future;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class TestingFutures {
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        ExecutorService service = Executors.newFixedThreadPool(1);
        FetchName task1 = new FetchName("Vaibhav");
        FetchName task2 = new FetchName("Kundu");
        FetchName task3 = new FetchName("Om");
        FetchName task4 = new FetchName("Subscribe");

        Future<String> name1 = service.submit(task1);
        Future<String> name2 = service.submit(task2);
        Future<String> name3 = service.submit(task3);
        Future<String> name4 = service.submit(task4);

        System.out.printf("\nFull Name is: %s", name1.get());
        System.out.printf("\nFull Name is: %s", name2.get());
        System.out.printf("\nFull Name is: %s", name3.get());
        System.out.printf("\nFull Name is: %s", name4.get());

        service.shutdown();
    }
}
