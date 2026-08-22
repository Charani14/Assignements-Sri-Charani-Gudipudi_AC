import java.util.Scanner;

public class MultipleStringLiterals {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        String str1 = new String(input).intern();
        String str2 = new String(input).intern();
        String str3 = new String(input).intern();

        boolean result = (str1 == str2) && (str2 == str3);

        System.out.println("All strings point to the same object: " + result);

        sc.close();
    }
}