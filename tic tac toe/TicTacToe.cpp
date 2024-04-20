#include <iostream>
#include <windows.h>
using namespace std;
char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';
void Draw()
{
    cout << "  ---------  \n";
    for (int i = 0; i < 3; i++)
    {
        cout << "|  ";
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << "|\n";
    }
    cout << "  ---------  \n";
}
void Replace()
{
    char pos;
    cout << "Enter Your postion(" << player << ") : \n";
    cin >> pos;
    if (pos >= '1' && pos <= '9')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (matrix[i][j] == pos)
                {
                    matrix[i][j] = player;
                    if (player == 'X')
                        player = 'O';
                    else
                        player = 'X';
                    break;
                }
            }
        }
    }
    else
    {
        // Invalid position entered
        cout << "Invalid position. Please try again.\n";
        return;
    }
}
char checkwinner()
{
    int x = 0, o = 0, counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 'X')
                x++;
            else if (matrix[i][j] == 'O')
                o++;
            if (x == 3)
                return 'X';
            else if (o == 3)
                return 'O';
        }
        x = 0;
        o = 0;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[j][i] == 'X')
                x++;
            else if (matrix[j][i] == 'O')
                o++;
            if (x == 3)
                return 'X';
            else if (o == 3)
                return 'O';
        }
        x = 0;
        o = 0;
    }

    // ‐------------------------------------------------------------------
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    else if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    // ‐------------------------------------------------------------------
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    else if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
        return 'O';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] != 'X' && matrix[i][j] != 'O')
                counter++;
        }
    }
    if (counter == 0)
        return '=';
    else
        return '*';
}
int main()
{
    while (checkwinner() == '*')
    {
        // system("cls");
        Draw();
        Replace();
    }
    Draw();
    char winner = checkwinner();
    if (winner == 'X')
    {
        cout << "\nplayer X won \n";
    }
    else if (winner == 'O')
    {
        cout << "\n player O won \n";
    }
    else
    {
        cout << "tie!";
    }
    return 0;
}