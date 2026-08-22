import java.util.*;

class Question15 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (j > 1)
                    System.out.print("*");
                System.out.print(i);
            }
            System.out.println();
        }

        for (int i = n-1; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                if (j > 1)
                    System.out.print("*");
                System.out.print(i);
            }
            System.out.println();
        }
    }
}