import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;

public class SnakesAndLadder {
    private static final int MAX_POSITION = 100;

    // Player class
    static class Player {
        private int position;

        public Player() {
            position = 0;
        }

        public int getPosition() {
            return position;
        }

        public int diceRoll() {
            Random rand = new Random();
            return rand.nextInt(6) + 1;
        }

        public void move(int newPosition) {
            if (newPosition <= MAX_POSITION) {
                position = newPosition;
            } else {
                System.out.println("Roll exceeds the board limit, try again.");
            }
        }
    }

    // Board class
    static class Board {
        private Map<Integer, Integer> snakes;
        private Map<Integer, Integer> ladders;

        // Snake and Ladder positions
        private final int s1s = 14, s1e = 7;   // Snake 1
        private final int s2s = 31, s2e = 26;  // Snake 2
        private final int L1s = 2, L1e = 15;   // Ladder 1
        private final int L2s = 10, L2e = 24;  // Ladder 2
        private final int L3s = 23, L3e = 42;  // Ladder 3
        private final int L4s = 50, L4e = 69;  // Ladder 4

        public Board() {
            snakes = new HashMap<>();
            ladders = new HashMap<>();

            snakes.put(s1s, s1e);
            snakes.put(s2s, s2e);

            ladders.put(L1s, L1e);
            ladders.put(L2s, L2e);
            ladders.put(L3s, L3e);
            ladders.put(L4s, L4e);
        }

        public int configurePosition(int position) {
            if (snakes.containsKey(position)) {
                System.out.println("Oops! Landed on a snake at " + position + ", sliding down to " + snakes.get(position) + ".");
                return snakes.get(position);
            }
            if (ladders.containsKey(position)) {
                System.out.println("Yay! Landed on a ladder at " + position + ", climbing up to " + ladders.get(position) + ".");
                return ladders.get(position);
            }
            return position;
        }

        // Draw board to visualize player positions
        public void drawBoard(Player p1, Player p2) {
            int bNum = MAX_POSITION;
            for (int i = 0; i < 101; i++) {
                System.out.print("=");
            }
            System.out.println();
            for (int i = 1; i <= 30; i++) {
                if (i % 3 != 0) {
                    for (int j = 0; j < 10; j++) {
                        System.out.print("|         ");
                    }
                    System.out.println("|");
                } else {
                    for (int p = 0; p < 10; p++) {
                        System.out.print("|");
                        if (p1.getPosition() == bNum) {
                            System.out.print("P1 ");
                        } else {
                            System.out.print("   ");
                        }
                        if (bNum == MAX_POSITION) {
                            System.out.print(" W ");
                        } else if (bNum == s1s) {
                            System.out.print("S1S");
                        } else if (bNum == s1e) {
                            System.out.print("S1E");
                        } else if (bNum == s2s) {
                            System.out.print("S2S");
                        } else if (bNum == s2e) {
                            System.out.print("S2E");
                        } else if (bNum == L1s) {
                            System.out.print("L1S");
                        } else if (bNum == L1e) {
                            System.out.print("L1E");
                        } else if (bNum == L2s) {
                            System.out.print("L2S");
                        } else if (bNum == L2e) {
                            System.out.print("L2E");
                        } else if (bNum < 10) {
                            System.out.print("0" + bNum + " ");
                        } else {
                            System.out.print(bNum + " ");
                        }

                        if (p2.getPosition() == bNum) {
                            System.out.print(" P2");
                        } else {
                            System.out.print("   ");
                        }
                        bNum--;
                    }
                    System.out.println("|");
                    for (int k = 0; k < 101; k++) {
                        System.out.print("=");
                    }
                    System.out.println();
                }
            }
        }
    }

    // Game logic
    public static void main(String[] args) {
        Player player1 = new Player();
        Player player2 = new Player();
        Board gameBoard = new Board();
        Scanner scanner = new Scanner(System.in);

        int turn = 1;
        boolean gameFinished = false;

        while (!gameFinished) {
            gameBoard.drawBoard(player1, player2);
            Player currentPlayer = (turn % 2 == 1) ? player1 : player2;
            System.out.println("Player " + (turn % 2 == 1 ? "1" : "2") + "'s turn. Press Enter to roll the dice.");
            scanner.nextLine(); // Wait for the user to press Enter

            int roll = currentPlayer.diceRoll();
            System.out.println("You rolled a " + roll + ".");

            int newPosition = currentPlayer.getPosition() + roll;
            newPosition = gameBoard.configurePosition(newPosition);
            currentPlayer.move(newPosition);

            System.out.println("Player " + (turn % 2 == 1 ? "1" : "2") + " is now on square " + currentPlayer.getPosition() + ".");

            // Check for win condition
            if (currentPlayer.getPosition() >= MAX_POSITION) {
                System.out.println("Player " + (turn % 2 == 1 ? "1" : "2") + " wins!");
                gameFinished = true;
            }

            System.out.println("\nPress Enter to continue to the next turn...");
            scanner.nextLine(); // Pause before next player's turn
            turn++;
        }

        scanner.close();
    }
}
