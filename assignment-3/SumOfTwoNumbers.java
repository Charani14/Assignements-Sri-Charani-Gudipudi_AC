import java.util.Scanner;

public class SumOfTwoNumbers {

    public static int sumOfTwoNumbers(int num1, int num2) {
        return num1 + num2;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter first number: ");
        int firstNumber = scanner.nextInt();

        System.out.print("Enter second number: ");
        int secondNumber = scanner.nextInt();

        int sum = sumOfTwoNumbers(firstNumber, secondNumber);

        // Display the result
        System.out.println("The sum of " + firstNumber + " and " 
                           + secondNumber + " is " + sum + ".");

        scanner.close();
    }
}
