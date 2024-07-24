#include <iostream>
using namespace std;

char board[3][3] = 
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentPlayer = 'X';


void displayBoard() 
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

void getPlayerMove() 
{
    int move;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O')
    {
        cout << "Invalid move Please try again" << endl;
        getPlayerMove();
    }

    else 
    {
        board[row][col] = currentPlayer;
    }
}

bool checkWin() 
{
    for (int i = 0; i < 3; ++i) 
    {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void switchPlayers() 
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}


int main() 
{
    bool gameActive = true;

    while (gameActive) 
    {
        displayBoard();

        getPlayerMove();

        if (checkWin())
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins" << endl;
            gameActive = false;
        }
        else if (checkDraw()) 
        {
            displayBoard();
            cout << "It's a draw" << endl;
            gameActive = false;
        }
        else 
        {
            switchPlayers();
        }
    }

}