import java.util.Scanner;

class Question18 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int n = sc.nextInt();

        System.out.print("Enter number of columns: ");
        int columns = sc.nextInt();

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= columns; j++) {
                System.out.print(i);
            }

            System.out.println();
        }

        sc.close();
    }
}