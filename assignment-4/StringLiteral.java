import java.util.Scanner;

public class StringLiteral {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter first string: ");
        String str1 = sc.nextLine();

        System.out.print("Enter second string: ");
        String str2 = sc.nextLine();

        boolean found = true;

        if (str1.length() != str2.length()) {
            found = false;
        } else {
            char[] chars1 = str1.toCharArray();
            char[] chars2 = str2.toCharArray();

            for (int i = 0; i < chars1.length; i++) {
                boolean characterFound = false;

                for (int j = 0; j < chars2.length; j++) {
                    if (chars1[i] == chars2[j]) {
                        characterFound = true;
                        break;
                    }
                }

                if (!characterFound) {
                    found = false;
                    break;
                }
            }
        }

        System.out.println("Both strings contain the same characters: " + found);

        sc.close();
    }
}