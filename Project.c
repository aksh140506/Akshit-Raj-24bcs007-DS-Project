#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char grid[3][3];
int i,j;
int row, column;
char player, computer;
void emptygrid()
{
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            grid[i][j] = ' ';
        }
    }
}

void displaygrid()
{
    printf("\n");
    for(i=0;i<3;i++)
    {
        printf(" %c  |  %c  |  %c ",grid[i][0],grid[i][1],grid[i][2]);
        //printf("\n     |     |      ");
        if(i<2)
        printf("\n----|-----|---\n");
    }
}

void computer_turn()
{
    srand(time(NULL));
    do
    {
        row = rand() % 3 + 1;
        column = rand() % 3 + 1;    
    }while(grid[row-1][column-1] != ' ');
    grid[row-1][column-1] = computer;
    displaygrid();
}

void computer_intelligence()
{
    for(i=0;i<3;i++)
    {
        if(grid[i][0] == player && grid[i][1] == player && grid[i][2] ==' ')
        {
            grid[i][2] = computer ;
            displaygrid();
        }
        else if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == ' ')
        {
            grid[2][i] = computer;
            displaygrid();
        }
        else if(grid[0][0] == player && grid[1][1] == player && grid[2][2] == ' ')
        {
            grid[2][2] = computer;
            displaygrid();
        }
        else if(grid[0][2] == player && grid[1][1] == player && grid[2][0] == ' ')
        {
            grid[2][0] = computer;
            displaygrid();
        }
        else if(grid[i][0] == player && grid[i][2] == player && grid[i][1] == ' ')
        {
            grid[i][1] = computer;
            displaygrid();
        }
        else if(grid[0][i] == player && grid[2][i] == player && grid[1][i] == ' ')
        {
            grid[1][i] = computer;
            displaygrid();
        }
        else if(grid[i][1] == player && grid[i][2] == player && grid[i][0] == ' ')
        {
            grid[i][0] = computer;
            displaygrid();
        }
        else if(grid[1][i] == player && grid[2][i] == player && grid[0][i] == ' ')
        {
            grid[0][i] = computer;
            displaygrid();
        }
        else if(grid[1][0] == player && grid[1][1] == player && grid[1][2] ==' ')
        {
            grid[1][2] = computer ;
            displaygrid();
        }
        else if (grid[0][1] == player && grid[1][1] == player && grid[2][1] == ' ')
        {
            grid[2][1] = computer;
            displaygrid();
        }
        else if(grid[1][0] == player && grid[1][2] == player && grid[1][1] == ' ')
        {
            grid[1][1] = computer;
            displaygrid();
        }
        else if(grid[0][1] == player && grid[2][1] == player && grid[1][1] == ' ')
        {
            grid[1][1] = computer;
            displaygrid();
        }
        else if(grid[1][1] == player && grid[1][2] == player && grid[1][0] == ' ')
        {
            grid[1][0] = computer;
            displaygrid();
        }
        else if(grid[1][1] == player && grid[2][1] == player && grid[0][1] == ' ')
        {
            grid[0][1] = computer;
            displaygrid();
        }
        else if(grid[2][0] == player && grid[2][1] == player && grid[2][2] ==' ')
        {
            grid[2][2] = computer ;
            displaygrid();
        }
        else if (grid[0][2] == player && grid[1][2] == player && grid[2][2] == ' ')
        {
            grid[2][2] = computer;
            displaygrid();
        }
        else if(grid[2][0] == player && grid[2][2] == player && grid[2][1] == ' ')
        {
            grid[2][1] = computer;
            displaygrid();
        }
        else if(grid[0][2] == player && grid[2][2] == player && grid[1][2] == ' ')
        {
            grid[1][2] = computer;
            displaygrid();
        }
        else if(grid[2][1] == player && grid[2][2] == player && grid[2][0] == ' ')
        {
            grid[2][0] = computer;
            displaygrid();
        }
        else if(grid[1][2] == player && grid[2][2] == player && grid[0][2] == ' ')
        {
            grid[0][2] = computer;
            displaygrid();
        }
        else 
        computer_turn();
    }
}

int player_winner()
{
    for (int i = 0; i < 3; i++) 
    {
        if ((grid[i][0] == player && grid[i][1] == player && grid[i][2] == player ) || 
        (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player ))
        return 1;
    }

    if ((grid[0][0] == player && grid[1][1] == player && grid[2][2] == player ) || 
    (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player ))
        return 1;

    return 0;
}

int computer_winner()
{
    for (int i = 0; i < 3; i++) 
    {
        if ((grid[i][0] == computer && grid[i][1] == computer && grid[i][2] == computer ) || 
        (grid[0][i] == computer && grid[1][i] == computer && grid[2][i] == computer ))
        return 1;
    }

    if ((grid[0][0] == computer && grid[1][1] == computer && grid[2][2] == computer ) || 
    (grid[0][2] == computer && grid[1][1] == computer && grid[2][0] == computer ))
        return 1;

    return 0;
}

int main()
{
    emptygrid();
    displaygrid();
    int choice;
    printf("\nEnter 1 for 'X' and 2 for 'O' : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        player = 'X';
        computer = 'O';
    }
    else if(choice==2)
    {
        player = 'O';
        computer = 'X';
    }
    else
    printf("Enter either 1 or 2");

    int moves = 0;
    while(1)
    {
        printf("\nYour Turn : Enter the position (row x column) at which you want to insert : ");
        scanf("%d x %d",&row, &column);
        grid[row-1][column-1] = player;
        displaygrid();

        if(player_winner())
        {
            printf("\nYou have won the game");
            break;
        }

        if(computer_winner())
        {
            printf("\nComputer has won the game");
            break;
        }

        moves++;
        if(moves==9)
        break;

        printf("\nComputer's Turn : ");
        computer_intelligence();

        if(player_winner())
        {
            printf("\nYou have won the game");
            break;
        }

        if(computer_winner())
        {
            printf("\nComputer has won the game");
            break;
        }

        moves++;
    }
    if(!player_winner() && !computer_winner())
    printf("\nThe game has ended in draw");
}