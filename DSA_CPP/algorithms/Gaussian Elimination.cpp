/*Gaussian_Elimination..
This program needs as a input, the original matrix and the number of rows and columns.
You are able to change the MAX value if you need to work with a bigger matrix*/

#include <iostream>
#define MAX 2000

void Gaussian_Elimination (double matrix[][MAX],int total_row,int total_column)
{
    //Some variables for make my loops
    int i,j,row,column;
    int swap_row = 0;

    //This array will divide the row that is procesing
    double divider[MAX];

    for (row = 0; row < total_row; t++)
    {
        //This make a matrix that will multiply the current row
        for (column = 1+swap_row; column < total_row; column++)
            divider[column] = (double)m[column][row] / m[row][row];

        //Now the divider's matrix will modify the original matrix
        for (i = 1+swap_row; i<total_row; i++)

            for (j=0; j<total_column; j++)
                matrix[i][j] = matrix[i][j] - matrix[row][j]*divider[i];
        swap_row++;
    }
}
