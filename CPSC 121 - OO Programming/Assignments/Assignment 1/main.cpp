/* Name: Jason Angel
* Assignment 1
* Section: 5
* 
* This assignment simulates the tic-tac-toe game using functions.

*/
#include <iostream>
#include <time.h>

using namespace std;

const int EMPTY{ 0 }, X{ 1 }, O{ 2 };

void playerAction(int[3][3], int);
void printBoard(int[3][3]);
void checkCells(int[3][3], int, bool&);
void playerVictory(int, bool&);

int main()
{
    srand(time(0));
    int board[3][3] = { EMPTY };
    int empty_slots = 9;
    bool game_over = false;
    int whose_turn;
    string line(50, '-');
    
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    // Randomly pick who goes first (was added for fun)
    int coin_toss = rand() % 2 + 1;
    if (coin_toss == 1) {
        cout << "Player X won the coin toss! Player X goes first." << endl;
        whose_turn = X;
    }
    else {
        cout << "Player O won the coin toss! Player O goes first." << endl;
        whose_turn = O;
    }

    cout << line << endl;
    cout << endl;

    // game_over is set to true if either player wins (controlled by playerVictory function, or if no one wins (Cat's game).
    while (game_over == false) {
        // printBoard function is nested inside the playerAction function
        playerAction(board, whose_turn);
        // printBoard and playerVictory functions are nested inside the checkCells function.
        checkCells(board, whose_turn, game_over);

        empty_slots--;
        if (empty_slots == 0) {
            cout << "Cat's game!" << endl;
            printBoard(board);
            game_over = true;
        }

        if (whose_turn == X) {
            whose_turn = O;
        }
        else {
            whose_turn = X;
        }
    }

    system("PAUSE");
    return 0;
}

// Function asks for user input. Has input validation, which takes place inside "do-while" loops.
void playerAction(int board[3][3], int whose_turn) {
    int row;
    int column;

    if (whose_turn == X) {
        cout << "-------------------" << endl;
        cout << "| PLAYER TURN 'X' |" << endl;
        cout << "-------------------" << endl;
    }
    else {
        cout << "-------------------" << endl;
        cout << "| PLAYER TURN 'O' |" << endl;
        cout << "-------------------" << endl;
    }

    printBoard(board);

    do {
        do {
            cout << "Which row would you like? (0-2)" << endl;
            cin >> row;
            if (row < 0 || row > 2) {
                cout << "Invalid input, please try again." << endl;
            }
        } while (row < 0 || row > 2);

        do {
            cout << "Which column would you like? (0-2)" << endl;
            cin >> column;
            if (column < 0 || column > 2) {
                cout << "Invalid input, please try again." << endl;
            }
        } while (column < 0 || column > 2);

        if (board[row][column] != EMPTY) {
            cout << "Illegal move. Pick another cell." << endl;
        }
        else {
            board[row][column] = whose_turn;
            break;
        }
    } while (board[row][column] != EMPTY);
}

// Function prints and updates cells of the board.
void printBoard(int board[3][3]) {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == X) {
                cout << "X ";
            }
            else if (board[i][j] == O) {
                cout << "O ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

// Function checks every cell to find out whether player X or O have won.  
void checkCells(int board[3][3], int whose_turn, bool& game_over) {
    // Check for diagonal win from the top left. If diagonal win, call "playerVictory" function to end game loop from main.
    if (board[0][0] == whose_turn && board[1][1] == whose_turn && board[2][2] == whose_turn) {
        printBoard(board);
        playerVictory(whose_turn, game_over);
    }

    // Check for diagonal win from the top right. If diagonal win, call "playerVictory" function to end game loop from main.
    if (board[0][2] == whose_turn && board[1][1] == whose_turn && board[2][0] == whose_turn) {
        printBoard(board);
        playerVictory(whose_turn, game_over);
    }

    for (int i = 0; i < 3; i++) {
        // Check for vertical win. If vertical win, call "playerVictory" function to end game loop from main.
        if (board[0][i] == whose_turn && board[1][i] == whose_turn && board[2][i] == whose_turn) {
            printBoard(board);
            playerVictory(whose_turn, game_over);
        }

        // Check for horizontal win. If horizontal win, call "playerVictory" function to end game loop from main.
        if (board[i][0] == whose_turn && board[i][1] == whose_turn && board[i][2] == whose_turn) {
            printBoard(board);
            playerVictory(whose_turn, game_over);
        }
    }
}

// Function sets "game_over" boolean to true if player X or O wins, ending game loop from main. It also prompts who won.
void playerVictory(int whose_turn, bool& game_over) {
    if (whose_turn == X) {
        cout << "X player wins!" << endl;
        game_over = true;
    }
    else {
        cout << "O player wins!" << endl;
        game_over = true;
    }
}
