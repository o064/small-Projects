#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;  // Size of the game board
const int NUM_MINES = 10;  // Number of mines

class MinesweeperGame {
private:
    vector<vector<char>> board;
    vector<vector<bool>> visited;
    int numUncovered;

public:
    MinesweeperGame() {
        board.resize(SIZE, vector<char>(SIZE, '-'));
        visited.resize(SIZE, vector<bool>(SIZE, false));
        numUncovered = 0;
        initializeBoard();
        placeMines();
    }

    void initializeBoard() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = '-';
            }
        }
    }

    void placeMines() {
        int count = 0;
        while (count < NUM_MINES) {
            int x = rand() % SIZE;
            int y = rand() % SIZE;
            if (board[x][y] != '*') {
                board[x][y] = '*';
                count++;
            }
        }
    }

    void printBoard() const {
        cout << "    ";
        for(int z = 0; z< SIZE; z++){
            cout << z << " ";
        }
        cout << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << i << " | ";
            for (int j = 0; j < SIZE; j++) {
                if(board[i][j] == '*')
                    cout << "- " ;
                else
                    cout << board[i][j] << ' ';
            }
            cout << " | " << i ;
            cout << endl;
        }
        cout << "    ";

        for(int z = 0; z< SIZE; z++){
            cout << z << " ";
        }
        cout << endl;
    }

    bool isValid(int x, int y) const {
        return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
    }

    int countAdjacentMines(int x, int y) const {
        int count = 0;
        int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

        for (int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY) && board[newX][newY] == '*') {
                count++;
            }
        }

        return count;
    }

    void revealCell(int x, int y) {
        if (!isValid(x, y) || visited[x][y]) {
            return;
        }

        visited[x][y] = true;

        if (board[x][y] == '*') {
            return;
        }

        int numMines = countAdjacentMines(x, y);
        board[x][y] = numMines + '0';

        if (numMines == 0) {
            int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
            int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

            for (int i = 0; i < 8; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                revealCell(newX, newY);
            }
        }
    }

    void playGame() {
        while (numUncovered < SIZE * SIZE - NUM_MINES) {
            cout << "Current board:" << endl;
            printBoard();

            int x, y;
            cout << "Enter the coordinates (x, y): ";
            cin >> x >> y;

            if (!isValid(x, y) || visited[x][y]) {
                cout << "Invalid move! Try again." << endl;
                continue;
            }

            if (board[x][y] == '*') {
                cout << "Game over! You hit a mine." << endl;
                break;
            }

            revealCell(x, y);
            numUncovered++;
        }

        if (numUncovered == SIZE * SIZE - NUM_MINES) {
            cout << "Congratulations! You won the game." << endl;
        }

        cout << "Final board:" << endl;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                    cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create and play the game
    MinesweeperGame game;
    game.playGame();

    return 0;
}