public class Evennumbers {

   public static void EvenNumbers() {
        int n = 1;
        System.out.println("Even numbers from 1 to 50 are: ");
        while (n <= 50) {
            if (n % 2 == 0) {
                System.out.print(n+ " ");
            }
            n++;
        }
    }

    public static void main(String[] args) {
        EvenNumbers();
    }
        
}
