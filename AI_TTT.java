import java.util.*;

class TTT
{
    Scanner sc = new Scanner(System.in);
    boolean matrixFlag = false;
    int[][] indexm = new int[][]{{9,9,9},{9,9,9},{9,9,9}};
    int[][] costm = new int[][]{{0,0,0},{0,0,0},{0,0,0}};


    void Play() {
        while (true) {
            Human();

            if (isDraw()) {
                System.out.println("The game is a draw");
                break;
            }

            if (isWinningPerson()) {
                System.out.println("Human wins");
                break;
            }

            AI();

            if (isDraw()) {
                System.out.println("The game is a draw");
                break;
            }

            if (isWinningAI()) {
                System.out.println("AI wins");
                break;
            }
        }
    }




    boolean isWinningPerson()
    {
        if(indexm[0][0]+indexm[1][0]+indexm[2][0] == 3 || indexm[0][1]+indexm[1][1]+indexm[2][1] == 3 || indexm[0][2]+indexm[1][2]+indexm[2][2] == 3)
        {
            return true;
        }
        if(indexm[0][0]+indexm[0][1]+indexm[0][2] == 3 || indexm[1][0]+indexm[1][1]+indexm[1][2] == 3 || indexm[2][0]+indexm[2][1]+indexm[2][2] == 3)
        {
            return true;
        }
        if(indexm[0][0]+indexm[1][1]+indexm[2][2] == 3 || indexm[0][2]+indexm[1][1]+indexm[2][0] == 3)
        {
            return true;
        }

        return false;
    }

    boolean isWinningAI()
    {
        if(indexm[0][0]+indexm[1][0]+indexm[2][0] == 0 || indexm[0][1]+indexm[1][1]+indexm[2][1] == 0 || indexm[0][2]+indexm[1][2]+indexm[2][2] == 0)
        {
            return true;
        }
        if(indexm[0][0]+indexm[0][1]+indexm[0][2] == 0 || indexm[1][0]+indexm[1][1]+indexm[1][2] == 0 || indexm[2][0]+indexm[2][1]+indexm[2][2] == 0)
        {
            return true;
        }
        if(indexm[0][0]+indexm[1][1]+indexm[2][2] == 0 || indexm[0][2]+indexm[1][1]+indexm[2][0] == 0)
        {
            return true;
        }

        return false;
    }

    boolean isDraw()
    {
        if(isFull() && !isWinningPerson() && !isWinningAI())return true;
        return false;
    }

    void Human()
    {
        int position = 0;
        int row, column;
        while(((position < 1) || (position > 9)))
        {
            System.out.print("Please enter the position where you want to place X : ");
            position = sc.nextInt();

            if(position < 1 || position > 9)
            {
                System.out.println("Please enter a position between 0 - 9");
                continue;
            }
            row = (position - 1)/3;
            column = (position - 1)%3;

            while(indexm[row][column] != 9)
            {
                System.out.println("This position is already taken, please enter a blank position");
                position = sc.nextInt();
                row = (position - 1)/3;
                column = (position - 1)%3;
            }

            indexm[row][column] = 1;
            drawMatrix();
        }
    }


    List<Integer> emptyPos()
    {
        List<Integer> list = new ArrayList<>();
        int pos = 1;
        while(pos < 10)
        {
            if(indexm[(pos-1)/3][(pos-1)%3] == 9)
            {
                list.add(pos);
            }
            pos++;
        }

        return list;
    }

    void AI()
    {

        List<Integer> list = new ArrayList<>();
        list = emptyPos();
        int optimalPos = minMax(list, false);

        indexm[(optimalPos-1)/3][(optimalPos-1)%3] = 0;
        drawMatrix();
    }

    boolean isFull()
    {
        for(int i = 0; i< 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(indexm[i][j] == 9)return false;
            }
        }

        return true;
    }

    void costMatrix()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(indexm[i][j] == 1)costm[i][j] = 1;
                else if(indexm[i][j] == 0)costm[i][j] = -1;
            }
        }
    }





    int minMax(List<Integer> empty, boolean isMaximizingPlayer) {
        if (isWinningAI()) {
            return -1;
        } else if (isWinningPerson()) {
            return 1;
        } else if (empty.isEmpty()) {
            return 0;
        }

        int bestValue = isMaximizingPlayer ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        int bestPosition = -1;

        for (Integer pos : empty) {
            int row = (pos - 1) / 3;
            int col = (pos - 1) % 3;

            indexm[row][col] = isMaximizingPlayer ? 0 : 1;

            int value = minMax(emptyPos(), !isMaximizingPlayer);

            if ((isMaximizingPlayer && value > bestValue) || (!isMaximizingPlayer && value < bestValue)) {
                bestValue = value;
                bestPosition = pos;
            }

            indexm[row][col] = 9;
        }

        return bestPosition;
    }



    void drawMatrix()
    {
        if(!matrixFlag)
        {
            int posCounter = 1;
            for(int i = 0; i < 3; i++)
            {
                System.out.print("| ");
                for(int j = 0; j < 3; j++)
                {
                    System.out.print(posCounter++ + " | ");
                }
                System.out.println("");
            }
        }

        else
        {
            for(int i = 0; i < 3; i++)
            {
                System.out.print("|");
                for(int j = 0; j < 3; j++)
                {
                    if(indexm[i][j] == 1)
                    {
                        System.out.print(" X |");
                    }
                    else if(indexm[i][j] == 0)
                    {
                        System.out.print(" O |");
                    }
                    else
                    {
                        System.out.print("   |");
                    }
                }
                System.out.println("");
            }
        }
        System.out.println("");
    }


}



public class AI_TTT {
    public static void main(String[] args) {

        TTT ttt = new TTT();
        ttt.drawMatrix();
        ttt.matrixFlag = true;
        ttt.Play();

    }
}