import java.util.Scanner;

public class AgeChecker {

    public static void checkAgeCategory(int age) {
       String category = (age < 18) ? "You are a minor."
                         : (age < 60) ? "You are an adult."
                         : "You are a senior citizen.";

        System.out.println(category);
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your age: ");
        int age = scanner.nextInt();
        checkAgeCategory(age);

        scanner.close();
    }
}
