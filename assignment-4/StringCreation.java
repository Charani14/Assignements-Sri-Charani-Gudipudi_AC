import java.util.Scanner;

public class StringCreation {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        String str1 = new String(input);
        String str2 = new String(input);

        System.out.println("Using == operator: " + (str1 == str2));
        System.out.println("Using .equals() method: " + str1.equals(str2));

        sc.close();
    }
}