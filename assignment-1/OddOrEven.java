/*
 * Q3: Check Odd or Even Number
 * 
 * Flowchart:
 * 
 *        [Start]
 *           |
 *     [Set number = 7]
 *           |
 *    {number % 2 == 0?}
 *        /     \
 *      Yes      No
 *       |        |
 *  [Print       [Print
 *  "Even"]      "Odd"]
 *       \       /
 *        [Stop]
 */

public class OddOrEven {
    public static void main(String[] args) {
        int number = 7;

        if (number % 2 == 0) {
            System.out.println(number + " is an even number.");
        } else {
            System.out.println(number + " is an odd number.");
        }
    }
}
