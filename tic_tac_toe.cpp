#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

// --------------------------  Tic-Tac-Toe  --------------------------
/*
    Version 1:
    - Basic console game implementation.
    - Two players: X and O.
    - Randomly selects the first player at the start.
    - Detects wins and draws.
    
    Notes:
    - In future versions, the logic for selecting the first player can be improved 
      (e.g., making the previous game's loser start first).
    - You can also enhance the interface with ASCII art.
*/

// ---------------------------------------------------------
// Function: printBoard
// Prints the current state of the 3x3 game board.
// Numbers are replaced by X or O once a move is made.
// ---------------------------------------------------------
void printBoard(int arr[3][3])
{
    cout<<"\t"<<"-------------------------------------------------"<<endl;
    for(int i=0;i<3;i++)
    {
        cout<< "\t"<<"|";
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]== 'O' || arr[i][j] == 'X')
            {
                cout<< "\t"<<char(arr[i][j])<< "\t"<< "|";
            }
            else
                cout<< "\t"<< arr[i][j]<< "\t"<<"|";                    
        }
        cout<<endl;
        cout<<"\t"<<"-------------------------------------------------";
        cout<<endl;
    }          
}

// ---------------------------------------------------------
// Function: makeMove
// Places the player's symbol (X or O) in the chosen cell.
// Returns true if the move is valid, false if the cell is occupied.
// ---------------------------------------------------------
bool makeMove(int arr[3][3], int choice, char player)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==choice)
            {
                arr[i][j]=player;
                return true;
            }
        }
    }
    return false;
}

// ---------------------------------------------------------
// Function: checkWin
// Checks all winning conditions:
//  - Horizontal rows
//  - Vertical columns
//  - Diagonals
// Returns true if a player has won.
// ---------------------------------------------------------
bool checkWin(int arr[3][3])
{
    // Horizontal checks
    if(arr[0][0]== arr[1][0]&&arr[0][0]== arr[2][0]) return true;
    else if(arr[0][1]== arr[1][1]&&arr[0][1]== arr[2][1]) return true;
    else if(arr[0][2]== arr[1][2]&&arr[0][2]== arr[2][2]) return true;

    // Vertical checks
    else if (arr[0][0]== arr[0][1]&&arr[0][0]== arr[0][2]) return true;
    else if (arr[1][0]== arr[1][1]&&arr[1][0]== arr[1][2]) return true;
    else if (arr[2][0]== arr[2][1]&&arr[2][0]== arr[2][2]) return true;

    // Diagonal checks
    else if (arr[0][0]== arr[1][1]&&arr[1][1]== arr[2][2]) return true;
    else if (arr[0][2]== arr[1][1]&&arr[1][1]== arr[2][0]) return true;

    // No win
    else return false;
}

// ---------------------------------------------------------
// Function: checkDraw
// Checks if all cells are filled without a winner.
// Returns true if the board is full and it's a draw.
// ---------------------------------------------------------
bool checkDraw(int arr[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]!= 'X' && arr[i][j]!= 'O')
                return false;
        }
    }
    return true;
}

// ---------------------------------------------------------
// Main Function
// Controls game flow:
//  - Menu (Start or Exit)
//  - Randomly chooses first player
//  - Handles turn-based input
//  - Prints the board after each move
//  - Detects win/draw conditions
//  - Allows replaying the game
// ---------------------------------------------------------
int main()
{
    char start;
    cout<< "\n=================================  Tic-Tac-Toe  =================================\n";
    cout<< "\nEnter (S) to Start the Game, or (E) to Exit: ";

    int firstchoice=0;
    while(true)
    {
        cin>> start;
        if(start == 'E' || start == 'e')
        {           
            exit(0);
        }

        // ---------------- Start Game ----------------
        else if(start == 'S' || start == 's')
        {   
            srand(time(0));
            firstchoice = rand()%2;
            char player;
            if(firstchoice)
                player = 'X';
            else
                player = 'O';

            int grid[3][3] = {
                {1,2,3},
                {4,5,6},
                {7,8,9}
            };
            
            // Print initial board
            cout<< "\nThis is the Board: "<<endl;
            printBoard(grid);

            // ---------------- Game Loop ----------------
            while(true)
            {
                int choice=0;
                if(player == 'X')
                {
                    cout<< "\n======  Now, Player [[ X ]]  ======\n";           
                    cout<< "\nChoose a Place from (1 -> 9) to put it in: ";
                }
                else
                {
                    cout<< "\n======  Now, Player [[ O ]]  ======\n";           
                    cout<< "\nChoose a Place from (1 -> 9) to put it in: ";
                }   

                cin>>choice;
                if(choice<1||choice>9)
                {
                    cout<< "\nError, Not a Place, Please Try Again...\n";
                }
                else
                {
                    bool test = false;
                    while(!test)
                    {
                        test = makeMove(grid,choice, player);
                        if(!test)
                        {
                            cout<< "\nError, Place Not Empty\nPlease Try Again: ";
                            cin>>choice;
                        }
                    }
                    printBoard(grid);
                }

                // Check for win
                if(checkWin(grid))
                {
                    cout<< "\n\nCongratulations, The Player [[ "<<player<< " ]] Has Won!\n";
                    break;
                }

                // Check for draw
                if(checkDraw(grid))
                {
                    cout<< "\n\nIt's a Draw, No Body Wins This Time!\n";
                    break;
                }
                
                // Switch turns
                if(player == 'X')
                    player = 'O';
                else
                    player = 'X';
            }
            cout<< "\n\nEnter (S) to Start the Game Again, or (E) to Exit: ";
        }  

        // ---------------- Invalid Input ----------------
        else if(start == 'S' || start == 's')
        {   
            cout<< "\n=================================  New Game  =================================\n";
        }
        else
        {
            cout<< "\nError, Pleas Try Again..\n";
            cout<< "\n\nEnter (S) to Start the Game Again, or (E) to Exit: ";
        }
    }

    return 0;
}
