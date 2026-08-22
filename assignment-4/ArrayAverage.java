import java.util.Scanner;

public class ArrayAverage {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] numbers = new int[5];
        int sum = 0;

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < 5; i++) {
            numbers[i] = sc.nextInt();
            sum += numbers[i];
        }

        double average = (double) sum / numbers.length;

        System.out.println("The average of the numbers is: " + average);

        sc.close();
    }
}
