import java.util.Scanner;

public class StringPoolIntern {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        String str1 = new String(input);
        String str2 = str1.intern();
        String str3 = input.intern();

        System.out.println("Is str2 and str3 pointing to the same object? " + (str2 == str3));

        sc.close();
    }
}