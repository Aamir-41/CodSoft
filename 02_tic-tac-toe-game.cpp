#include<iostream>
using namespace std;


char board[3][3]; // 3x3 board
char currentMarker;
int currentPlayer;

// Initialize empty board
void resetBoard() {
    char count = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = count++;
}

// Display current board state
void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

// Place marker at position
bool placeMarker(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

// Check win condition
bool checkWin() {
    // Check rows, columns and diagonals
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == currentMarker && board[i][1] == currentMarker && board[i][2] == currentMarker) ||
            (board[0][i] == currentMarker && board[1][i] == currentMarker && board[2][i] == currentMarker))
            return true;

    if ((board[0][0] == currentMarker && board[1][1] == currentMarker && board[2][2] == currentMarker) ||
        (board[0][2] == currentMarker && board[1][1] == currentMarker && board[2][0] == currentMarker))
        return true;

    return false;
}

// Switch players
void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
        currentPlayer = 2;
    } else {
        currentMarker = 'X';
        currentPlayer = 1;
    }
}

// Game function
void playGame() {
    resetBoard();
    currentMarker = 'X';
    currentPlayer = 1;
    int moves = 0;

    drawBoard();

    while (true) {
        int cell;
        cout << "Player " << currentPlayer << " (" << currentMarker << "), enter your move (1-9): ";
        cin >> cell;

        if (cell < 1 || cell > 9) {
            cout << "Invalid cell number. Try again.\n";
            continue;
        }

        if (!placeMarker(cell)) {
            cout << "Cell already occupied. Try again.\n";
            continue;
        }

        drawBoard();
        moves++;

        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (moves == 9) {
            cout << "It's a draw!\n";
            break;
        }

        swapPlayerAndMarker();
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
