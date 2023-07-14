#include <stdio.h>


//Player-1 AI - 0
//Player-2 Person - 1


int flag[] = {0,0}; //isWinning, isDraw
int chance[] = {0,0}; //AI, Person
int indexm[][3] = {{9,9,9},{9,9,9},{9,9,9}};
int flag_draw = 0;
int row  = 0, column = 0;
int position;
int matrix_drawing_flag = 0;

void place(int);


int chanceAI()
{
    chance[0] = 1;
    place(position);
}

int chancePerson()
{
    chance[1] = 1;
    place(position);
}

int isWinningAI() //AI is winning
{
    if(indexm[0][0]+indexm[1][0]+indexm[2][0] == 0 || indexm[0][1]+indexm[1][1]+indexm[2][1] == 0 || indexm[0][2]+indexm[1][2]+indexm[2][2] == 0)
    {
        //return 1;
        flag[0] = 1;
    }
    if(indexm[0][0]+indexm[0][1]+indexm[0][2] == 0 || indexm[1][0]+indexm[1][1]+indexm[1][2] == 0 || indexm[2][0]+indexm[2][1]+indexm[2][2] == 0)
    {
        //return 1;
        flag[0] = 1;
    }
    if(indexm[0][0]+indexm[1][1]+indexm[2][2] == 0 || indexm[0][2]+indexm[1][1]+indexm[2][0] == 0)
    {
        //return 1;
        flag[0] = 1;
    }

    if(flag[0])return 1;
    else return 0;
}

int isWinningPerson()
{
        if(indexm[0][0]+indexm[1][0]+indexm[2][0] == 3 || indexm[0][1]+indexm[1][1]+indexm[2][1] == 3 || indexm[0][2]+indexm[1][2]+indexm[2][2] == 3)
    {
        //return 1;
        flag[1] = 1;
    }
    if(indexm[0][0]+indexm[0][1]+indexm[0][2] == 3 || indexm[1][0]+indexm[1][1]+indexm[1][2] == 3 || indexm[2][0]+indexm[2][1]+indexm[2][2] == 3)
    {
        //return 1;
        flag[1] = 1;
    }
    if(indexm[0][0]+indexm[1][1]+indexm[2][2] == 3 || indexm[0][2]+indexm[1][1]+indexm[2][0] == 3)
    {
        //return 1;
        flag[1] = 1;
    }

    if(flag[1])return 1;
    else return 0;
}

void place(int pos)
{ //Add conditions of if inside chanceAI and if inside chancePerson
    if(chance[1] == 1)
    {
        if(pos>9 || pos<1)
        {
            printf("Position out of bound... please put position b/w 1-9\n");
            chance[1] = 0;
            return;
        }
        column = (pos - 1) % 3;
        row = (pos - 1) / 3;
        int pos_value = indexm[row][column];
        if(pos_value != 9|| pos_value == 0 || pos_value == 1)
        {
            printf("Sorry ... You can't place the X here !\n");
            chance[1] = 0;

        }
        else
        {
            indexm[row][column] = 1;
            // chance[1] = 0;
        }
    }


    else if(chance[0] == 1)
    {
        if(pos>9 || pos<1)
        {
            printf("Position out of bound... please put position b/w 1-9\n");
            chance[0] = 0;
            return;
        }
        int column = (pos - 1) % 3;
        int row = (pos - 1) / 3;
        int pos_value = indexm[row][column];
        if(pos_value != 9|| pos_value == 1 || pos_value == 0)
        {
            printf("Sorry ... You can't place the O here !\n");
            chance[0] = 0;
        }
        else
        {
            indexm[row][column] = 0;
            // chance[0] = 0;
        }
    }

}


int isDraw()
{
    if(!isWinningAI() || !isWinningPerson())
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(indexm[i][j] == 9)
                {
                    flag_draw = 0;
                    break;
                }
                else
                {
                    flag_draw = 1;
                }
            }
            if(!flag_draw)
            {
                break;
            }
        }
    }
    if(flag_draw)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void drawMatrix()
{
    if(matrix_drawing_flag)
    {
         for(int i = 0; i < 3; i++)
        {
            printf("|");
            for(int j = 0; j < 3; j++)
            {
                if(indexm[i][j] == 0)
                {
                    printf(" O |");
                }
                else if(indexm[i][j] == 1)
                {
                    printf(" X |");
                }
                else
                {
                printf("   |");
                }
            }
            printf("\n\n");
        }
    }
    else
    {
        int pos_counter = 1;
        for(int i = 0; i < 3; i++)
        {
            printf("|");
            for(int j = 0; j < 3; j++)
            {
                printf(" %d |", pos_counter);
                pos_counter++;
            }
            printf("\n\n");
        }
    }

}

void main()
{
    printf("WELCOME TO TIC TAC TOE !!!!! \n\n");
    drawMatrix();
    while(!isWinningAI() || !isWinningPerson() || !isDraw())
    {
        matrix_drawing_flag = 1;
        while(chance[0] != 1)
        {
            printf("AI.... pleaee enter the position where you want to place O: - ");
            scanf("%d", &position);
          chanceAI();
        }
        drawMatrix();
        chance[0] = 0;
        if(isWinningAI())
        {
            printf("THE AI HAS WON !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
             break;
        }
        if(isWinningPerson())
        {
            printf("THE PERSON HAS WON !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;
        }
        if(isDraw())
        {
            printf("THE MATCH IS DRAW !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;
        }
        while(chance[1] != 1)
        {
            printf("PERSON.... pleaee enter the position where you want to place X: - ");
            scanf("%d", &position);
            chancePerson();
        }
        drawMatrix();
        chance[1] = 0;
        if(isWinningAI())
        {
            printf("THE AI HAS WON !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;
        }
        if(isWinningPerson())
        {
            printf("THE PERSON HAS WON !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;
        }
        if(isDraw())
        {
            printf("THE MATCH IS DRAW !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;
        }
    }

}
