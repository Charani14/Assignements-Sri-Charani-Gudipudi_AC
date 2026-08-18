/*
 * Q7: Find the Largest of Three Numbers
 * 
 * Flowchart:
 * 
 *           [Start]
 *              |
 *    [Set a=25, b=40, c=15]
 *              |
 *       {a > b AND a > c?}
 *          /        \
 *        Yes         No
 *         |           |
 *   [largest = a]  {b > c?}
 *         |        /     \
 *         |      Yes      No
 *         |       |        |
 *         | [largest=b] [largest=c]
 *          \      |       /
 *           [Print largest]
 *                |
 *             [Stop]
 */

public class LargestOfThree {
    public static void main(String[] args) {
        int n1 = 25;
        int n2 = 40;
        int n3 = 15;

        int largest;

        if (n1 > n2 && n1 > n3) {
            largest = n1;
        } else if (n2 > n3) {
            largest = n2;
        } else {
            largest = n3;
        }

        System.out.println("Numbers: " + n1 + ", " + n2 + ", " + n3);
        System.out.println("Largest number is: " + largest);
    }
}
