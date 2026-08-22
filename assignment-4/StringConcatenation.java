import java.util.Scanner;

public class StringConcatenation {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first string: ");
        String str1 = sc.nextLine();

        System.out.print("Enter second string: ");
        String str2 = sc.nextLine();

        String str3 = str1 + str2;

        System.out.println("Is str3 pointing to the same object as str1? " + (str3 == str1));

        sc.close();
    }
}
