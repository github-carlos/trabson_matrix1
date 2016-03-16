#include "matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(const int rows , const int columns )
{

    this->rows = rows;
    this->columns = columns;
    vet_matrix = new int*[this->rows];//Columns allocation

    for(int i = 0; i < this->rows; i++)
        vet_matrix[i] = new int[this->columns]; //Rows allocation
}
void Matrix::set(int x, int y, int value) //
{
    vet_matrix[x][y] = value;
}

Matrix Matrix::transposed()
{
    Matrix aux(columns, rows);

    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            aux.set(i,j,vet_matrix[j][i]);
        }
    }

    return aux;
}
void Matrix::fill()
{
    int k = 0;
    for(int i = 0; i < rows ; i++)
    {
        for(int j = 0; j < columns; j++){
            cout << "[" << i << "] " << "[" << j << "] = ";
            cin >> k;
            vet_matrix[i][j] = k;
        }
    }
}

Matrix Matrix::operator +(Matrix b)
{
    if(equal_dimensions(b))
    {
        Matrix c(rows, columns);

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                c.set(i, j, vet_matrix[i][j] + b.getElement(i, j));
            }
        }
        return c;
    }

    throw std::string("\nNao eh possivel fazer esta soma!");

}

Matrix Matrix::operator -(Matrix b)
{
    if(equal_dimensions(b))
    {
        Matrix c(rows, columns);

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns;j++)
            {
                c.set(i, j, vet_matrix[i][j] - b.getElement(i, j));
            }
        }
        return c;
    }
    throw  std::string("\nNao eh possivel fazer a subtracao.\n");
}

Matrix Matrix::operator *(Matrix b)
{
    if(columnsA_Equal_LinesB(b))
    {
        Matrix c(rows, b.getColumns());

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; i < b.getColumns(); j++)
            {
//                c.set(i, j, vet_matrix[i][j]=0);

                for(int k = 0; k < columns; k++)
                {
                    c.set(i, j, c.getElement(i,j) + vet_matrix[i][k] * b.getElement(k,j));
                }
            }
        }
        return c;
    }
    throw std::string("\nNao eh possivel fazer a multiplicacao.\n");
}

bool Matrix::upperTriangular()
{
    if(square()==true)
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(vet_matrix[i][j] != 0)
                    return false;
                return true;
            }
        }
}

bool Matrix::lowerTriangular()
{
    if(square()==true)
        for(int i = 0; i < rows; i++)
        {
            for(int j = i + 1; j < rows; j++)
            {
                if(vet_matrix[i][j] != 0)
                    return false;
                return true;
            }
        }
}
