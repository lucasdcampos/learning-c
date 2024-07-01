// 7/1/2024
// tictactoe.c
// ugly code, but it works

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void draw_board();
void make_move();
char check_winner();

enum Player
{
    Human, Computer
};

char board[3][3];
enum Player player = Human;

const char HUMAN_SYMBOL = 'X';
const char COMPUTER_SYMBOL = 'O';

int main()
{
    srand(time(0));

    draw_board();
    while(check_winner() == '\0')
    {
        make_move();
    }

    char winner[15] = "Draw";

    if(check_winner() == HUMAN_SYMBOL)
    {
        strcpy(winner, "Human");
    }
    else if(check_winner() == COMPUTER_SYMBOL)
    {
        strcpy(winner, "Computer");
    }

    printf("\n------------------------\n");
    printf("Winner: %s\n", winner);
    printf("\n");

    return 0;
}

void draw_board()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == '\0')
                board[i][j] = ' ';

            printf(" %c ", board[i][j]);

            if(j != 2)
                printf("|");
            
        }

        if(i != 2)
            printf("\n---|---|---\n");
    }

    printf("\n\n");
}

void make_move()
{
    int row, col;

    if(player == Human)
    {
        do
        {
            printf("Type the row: ");
            scanf("%d", &row);

            printf("Type the col: ");
            scanf("%d", &col);

            row--;
            col--;

            if(board[row][col] != ' ')
                printf("This Square is already occupied!\n");
        }
        while(board[row][col] != ' ');

        board[row][col] = HUMAN_SYMBOL;

        player = Computer;
    }

    else
    {
        do
        {
            col = rand() % 3;
            row = rand() % 3;
        }
        while(board[row][col] != ' ');

        board[row][col] = COMPUTER_SYMBOL;

        player = Human;
    }

    // We invert the Player here
    printf("%s plays:\n", player == Human ? "Computer" : "\nHuman");
    draw_board();
}

// ugly code, i'll fix it later (probably not)
char check_winner()
{
    // Checking if all the columns are equal
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            if(board[i][0] != ' ')
                return board[i][0];
        }
    }

    // Checking if all the rows are equal
    for(int j = 0; j < 3; j++)
    {
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j])
        {
            if(board[0][j] != ' ')
                return board[0][j];
        }
    }

    // Checking if the diagonals are equal
    if(board[1][1] != ' ')
    {
        char c = board[1][1];

        if(board[0][0] == c && board[2][2] == c)
            return c;
        
        if(board[0][2] == c && board[2][0] == c)
            return c;
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
                return '\0';
        }
    }

    return 'd';

}