import java.util.Scanner;

public class TicTacToe {
    private static char[][] board = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    private static char currentPlayer = 'X';

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean gameRunning = true;

        System.out.println("Welcome to Tic-Tac-Toe!");
        printBoard();

        while (gameRunning) {
            System.out.println("Player " + currentPlayer + "'s turn. Enter a position (1-9):");
            int position = scanner.nextInt();

            if (isValidMove(position)) {
                placeMark(position);
                printBoard();

                if (checkWin()) {
                    System.out.println("Player " + currentPlayer + " wins!");
                    gameRunning = false;
                } else if (isBoardFull()) {
                    System.out.println("It's a draw!");
                    gameRunning = false;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  // Switch player
                }
            } else {
                System.out.println("This move is not valid. Try again.");
            }
        }

        System.out.println("Game Over!");
        scanner.close();
    }

    private static void printBoard() {
        System.out.println("-------------");
        for (int i = 0; i < 3; i++) {
            System.out.print("| ");
            for (int j = 0; j < 3; j++) {
                System.out.print(board[i][j] + " | ");
            }
            System.out.println();
            System.out.println("-------------");
        }
    }

    private static boolean isValidMove(int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        return position >= 1 && position <= 9 && board[row][col] == ' ';
    }

    private static void placeMark(int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        board[row][col] = currentPlayer;
    }

    private static boolean checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }

        return false;
    }

    private static boolean isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
}
