public class GoodMorning {
    public static void main(String[] args) {
        int time = 8; // Time in 24-time format

        if (time >= 5 && time < 12) {
            System.out.println("Good Morning!");
        } else {
            System.out.println("It is not morning. The current time is: " + time);
        }
    }
}
