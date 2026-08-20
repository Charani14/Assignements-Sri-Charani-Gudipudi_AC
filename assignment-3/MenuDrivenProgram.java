import java.util.Scanner;

public class MenuDrivenProgram {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n===== MENU =====");
            System.out.println("1. Grade Evaluation System");
            System.out.println("2. Leap Year Check");
            System.out.println("3. Day of the Week");
            System.out.println("4. Identify Default Values of Variables");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            choice = scanner.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter your marks: ");
                    int marks = scanner.nextInt();

                    if (marks >= 90) {
                        System.out.println("Grade: A");
                    } else if (marks >= 80) {
                        System.out.println("Grade: B");
                    } else if (marks >= 70) {
                        System.out.println("Grade: C");
                    } else if (marks >= 60) {
                        System.out.println("Grade: D");
                    } else {
                        System.out.println("Grade: F");
                    }
                    break;

                case 2:
                    System.out.print("Enter a year: ");
                    int year = scanner.nextInt();

                    if ((year % 400 == 0) || 
                        (year % 4 == 0 && year % 100 != 0)) {
                        System.out.println(year + " is a leap year.");
                    } else {
                        System.out.println(year + " is not a leap year.");
                    }
                    break;

                case 3:
                    System.out.print("Enter a number (1-7): ");
                    int day = scanner.nextInt();

                    switch (day) {
                        case 1:
                            System.out.println("Monday");
                            break;
                        case 2:
                            System.out.println("Tuesday");
                            break;
                        case 3:
                            System.out.println("Wednesday");
                            break;
                        case 4:
                            System.out.println("Thursday");
                            break;
                        case 5:
                            System.out.println("Friday");
                            break;
                        case 6:
                            System.out.println("Saturday");
                            break;
                        case 7:
                            System.out.println("Sunday");
                            break;
                        default:
                            System.out.println("Invalid day number.");
                    }
                    break;

                case 4:
                    System.out.println("Default values of instance variables:");

                    DefaultValues values = new DefaultValues();

                    System.out.println("int: " + values.intValue);
                    System.out.println("double: " + values.doubleValue);
                    System.out.println("float: " + values.floatValue);
                    System.out.println("long: " + values.longValue);
                    System.out.println("boolean: " + values.booleanValue);
                    System.out.println("char: '" + values.charValue + "'");
                    System.out.println("String: " + values.stringValue);
                    break;

                case 5:
                    System.out.println("Exiting the program. Thank you!");
                    break;

                default:
                    System.out.println("Invalid choice. Please select 1-5.");
            }

        } while (choice != 5);

        scanner.close();
    }
}

class DefaultValues {

    int intValue;
    double doubleValue;
    float floatValue;
    long longValue;
    boolean booleanValue;
    char charValue;
    String stringValue;
}
