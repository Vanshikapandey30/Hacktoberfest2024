package DSA.Java;

public class patternQuestions {

    public static void printDiamondPattern(int n) {
        int space = n - 1;

        // Top half of the diamond
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < space; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
            space--;
        }

        // Bottom half of the diamond
        space = 0;
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < space; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j < i; j++) {
                System.out.print("* ");
            }
            System.out.println();
            space++;
        }
    }

    public static void main(String[] args) {
        int n = 5; // You can change this value to get different sizes of the diamond
        printDiamondPattern(n);
    }
}