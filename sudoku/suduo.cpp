#include<iostream>
#include<vector>
using namespace std;
const int Size = 9 ;
class Suduko{
private:
    vector<vector<int>> board;
public:
    Suduko(){
        board.resize(Size,vector<int>(Size,0));
    }
    void setCell(int r,int c,int val){
        board[r][c] =val;

    }
    int  getCell(int r,int c){
        return board[r][c];
    }
    bool isSafe(int r , int c,int num){
//        check row and col
        for(int i =0 ; i < Size ; i++){
            if(board[r][i] == num || board[i][c] == num  )
                return false;
        }
//        check boxes
        int rowS = r - r%3;
        int colS = c - c%3;
        for(int i = 0 ; i < 3 ; i ++){
            for(int j =0 ; j < 3 ; j++){
                if(board[rowS + i ][colS + j] ==num)
                    return false;
            }
        }
        return true;
    }
    bool findEmptyCell(int& row , int& col){
        for( row = 0 ; row < Size ; row ++){
            for(col =0 ; col < Size ; col++){
                if (board[row][col] == 0) {
                    return true;
                }

            }
        }
        return false;
    }
    bool Solve(){
        int row,col;
        if(!findEmptyCell(row,col)){
            return true;
        }
        for(int i = 1 ; i <=Size; i++){
            if(isSafe(row,col,i)){
                board[row][col] = i ;
                if(Solve()){
                    return true;
                }
                board[row][col] = 0 ;
            }
        }
        return false;
    }
    void display(){
        for(int i = 0 ; i < Size ; i++){
            for(int j = 0 ; j < Size ; j++){
                cout << board[i][j] << " ";
            }
            cout << endl ;
        }
    }
};

int main() {
    Suduko puzzle;

    // Set up the Sudoku puzzle
    puzzle.setCell(0, 0, 5);
    puzzle.setCell(0, 1, 3);
    puzzle.setCell(0, 4, 7);
    puzzle.setCell(1, 0, 6);
    puzzle.setCell(1, 3, 1);
    puzzle.setCell(1, 4, 9);
    puzzle.setCell(1, 5, 5);
    puzzle.setCell(2, 1, 9);
    puzzle.setCell(2, 2, 8);
    puzzle.setCell(2, 7, 6);
    puzzle.setCell(3, 0, 8);
    puzzle.setCell(3, 4, 6);
    puzzle.setCell(3, 8, 3);
    puzzle.setCell(4, 0, 4);
    puzzle.setCell(4, 3, 8);
    puzzle.setCell(4, 5, 3);
    puzzle.setCell(4, 8, 1);
    puzzle.setCell(5, 0, 7);
    puzzle.setCell(5, 4, 2);
    puzzle.setCell(5, 8, 6);
    puzzle.setCell(6, 1, 6);
    puzzle.setCell(6, 6, 2);
    puzzle.setCell(6, 7, 8);
    puzzle.setCell(7, 3, 4);
    puzzle.setCell(7, 4, 1);
    puzzle.setCell(7, 5, 9);
    puzzle.setCell(7, 8, 5);
    puzzle.setCell(8, 4, 8);
    puzzle.setCell(8, 7, 7);
    puzzle.setCell(8, 8, 9);

    std::cout << "Sudoku Puzzle:" << std::endl;
    puzzle.display();

    std::cout << std::endl << "Solving the puzzle..." << std::endl;
    if (puzzle.Solve()) {
        std::cout << std::endl << "Solution:" << std::endl;
        puzzle.display();
    } else {
        std::cout << "No solution exists for the given puzzle." << std::endl;
    }

    return 0;
}