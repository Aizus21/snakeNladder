/*
sankes_ladder.cpp:
This is sankes_ladder Game program. This program will display
sankes and ladder Board.
It will take two player names. Gives you winner of the Game by
using Random function.
Date : 18/04/2009.
Author: Afiz ******
*/
#include <iostream>
#include <time.h> // including header files.


using namespace std;


class player // player class
{
public: // class members declaration.
    char name[50];
    player(); // constructor declaration.
    int currentposition;
    int previousposition;
    int Rollingdie(); // Rollingdie function.
};
player ::player() // constructor implementation.
{
    currentposition = 1; // initialization of variables.
    previousposition = 1;
}

int player ::Rollingdie() // Rollingdie function.
{
    return (rand() % (6) + 1); // using Random function.
}

class board // board class.
{
    int Board[10][10]; // board array
public:
    board();                    // board constructor.
    int nextposition(int, int); // declaration of nextpostion function.
    void display();             // display function.
};
board::board() // creating board
{
    int k = 1;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            Board[i][j] = k++; // assiging values to board
}
int board ::nextposition(int a, int b) // implemenation of nextposition function.
{
    switch (a + b)
    { // creting ladders.
    case 8:
        cout << " You Got Riddle \n";
        return 31;
        break;

    case 15:
        cout << " You Got Riddle \n";
        return 97;
        break;
    case 42:
        cout << " You Got Riddle \n";
        return 81;
        break;
    case 66:
        cout << " You Got Riddle \n";
        return 87;
        break;
    // creating snakes
    case 24:
        cout << "You answer it incorrect \n";
        return 1;
        break;
    case 55:
        cout << "You answer it incorrect\n";
        return 13;
        break;
    case 71:
        cout << "You answer it incorrect \n";
        return 29;
        break;
    case 88:
        cout << "You answer it incorrect \n";
        return 54;
        break;
    case 99:
        cout << "You answer it incorrect \n";
        return 6;
        break;
    default:
        return (a + b);
        break;
    }
}
void board ::display() // definition of display function.
{
    for (int i = 9; i >= 0; i--)
    {
        cout << endl;
        if (i % 2 != 0)
        { // Add line Display Code
            for (int j = 9; j >= 0; j--)
            {
                if (Board[i][j] == 1 || Board[i][j] == 24) // naik turun snake and ladder

                    cout
                        << Board[i][j] << "R\t";
                else if (Board[i][j] == 13 || Board[i][j] == 55)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 29 || Board[i][j] == 71)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 54 || Board[i][j] == 88)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 6 || Board[i][j] == 99)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 8 || Board[i][j] == 31)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 15 || Board[i][j] == 97)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 42 || Board[i][j] == 81)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 66 || Board[i][j] == 87)
                    cout << Board[i][j] << "R\t";
                else
                    cout << Board[i][j] << "\t";
            }
        }
        else
        {
            for (int j = 0; j < 10; j++)
                if (Board[i][j] == 1 || Board[i][j] == 24) // Even Line display code

                    cout << Board[i][j] << "RS1\t";
                else if (Board[i][j] == 13 || Board[i][j] == 55) // this is all about creating snakes and ladder

                    cout
                        << Board[i][j] << "R\t";
                else if (Board[i][j] == 29 || Board[i][j] == 71)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 54 || Board[i][j] == 88)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 6 || Board[i][j] == 99)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 8 || Board[i][j] == 31)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 15 || Board[i][j] == 97)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 42 || Board[i][j] == 81)
                    cout << Board[i][j] << "R\t";
                else if (Board[i][j] == 66 || Board[i][j] == 87)
                    cout << Board[i][j] << "R\t";
                else
                    cout << Board[i][j] << "\t";
        }
    }
}
int main() // main class
{
   // srand(time(0)); // it is random function.
    board b;        // creation object in board class.
    cout << "\n****************************************************************************\n";
    cout << "\t\tRIDDLE BOARD";
    cout << "\n****************************************************************************\n";
    b.display(); // calling display function.
    cout << "\n****************************************************************************\n";
    player player1, player2; // creationg objects in player class.
    cout << "Enter First player Name\n";
    cin >> player1.name;
    cout << "Enter second player Name\n";
    cin >> player2.name;
    cout << endl;
    cout << "***********************\n##### Main Game #####\n***********************" << endl;

    int score;
    
    while (true)
    {
        // player One logic part.
        player1.previousposition = player1.currentposition;
        score = player1.Rollingdie(); // calling Rollingdie function.
        player1.currentposition = b.nextposition(score, player1.previousposition);
        if (player1.currentposition > 100)
            player1.currentposition = player1.previousposition;
        cout << player1.name << "\t" << player1.currentposition << "\t" << score << endl;
        if (player1.currentposition == 100)

        {
            cout << player1.name << " won the Game " << endl;
            break;
        }
        // player Two logic part
        player2.previousposition = player2.currentposition;
        score = player2.Rollingdie(); // calling rollingdie function and assigning  value to score

        player2.currentposition = b.nextposition(score, player2.previousposition);
        if (player2.currentposition > 100)
            player2.currentposition = player2.previousposition;
        cout << player2.name << "\t" << player2.currentposition << "\t" << score << endl;
        if (player2.currentposition == 100)
        {
            cout << player2.name << " won the Game " << endl;
            break;
        }
    }
    system("pause");
    return 1;
}