public class GradeEvaluation {
    public static void main(String[] args) {

        // Predefined marks
        int maths = 80;
        int science = 85;
        int history = 90;

        // Calculate average
        double average = (maths + science + history) / 3.0;

        // Determine grade
        char grade;

        if (average >= 90) {
            grade = 'A';
        } else if (average >= 70) {
            grade = 'B';
        } else if (average >= 50) {
            grade = 'C';
        } else if (average >= 30) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        // Display result
        System.out.println("Average Marks: " + average);
        System.out.println("Grade: " + grade);
    }
}