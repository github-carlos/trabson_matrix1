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
        int value = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < b.getColumns(); j++)
            {
                for(int k = 0; k < columns; k++)
                {
                    value += vet_matrix[i][k] * b.getElement(k, j);

                }
                c.set(i, j, value);
                value = 0;
            }
        }
        return c;
    }
    throw std::string("\nNao eh possivel fazer a multiplicacao.\n");
}
Matrix Matrix::operator *(int x)
{
        Matrix c(rows, columns);

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                c.set(i, j, vet_matrix[i][j] * x);
            }
        }
        return c;
}

bool Matrix::operator ==(Matrix &b)
{
    return igual(b);
}

bool Matrix::operator !=(Matrix &b)
{
    return !igual(b);
}
bool Matrix::upperTriangular()
{
    if(square())
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(vet_matrix[i][j] != 0)
                    return false;

            }
        }
        return true;
    }
    return false;
}

bool Matrix::lowerTriangular()
{
    if(square()==true)
    {
        for(int i = 0; i < rows - 1; i++)
        {
            for(int j = i + 1; j < rows; j++)
            {
                if(vet_matrix[i][j] != 0)
                    return false;
           }

        }
        return true;
    }
    return false;
}

bool Matrix::simetrica(Matrix a)
{
    if(a.square())
    {
        Matrix b = a.transposed();

        return a == b;

    }
    return false;
}

bool Matrix::identidade()
{
    if(square())
    {

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(i != j && vet_matrix[i][j] != 0 || i == j && vet_matrix[i][j] != 1)
                    return false;
            }
        }

        return true;
    }
}

bool Matrix::igual(Matrix &b)
{
    if(equal_dimensions(b))
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(vet_matrix[i][j] != b.getElement(i,j))
                    return false;
            }
        }
        return true;
    }
    return false;
}

bool Matrix::permutacao()
{
    Matrix a(rows, columns);
    Matrix t(rows, columns);
    Matrix iden(rows, columns);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            a.set(i, j, vet_matrix[i][j]);
        }
    }
    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            t.set(i,j,vet_matrix[j][i]);
        }
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(i == j)
            {
                iden.set(i, j, vet_matrix[i][j] = 1);
            }
            else
            {
                iden.set(i, j, vet_matrix[i][j] = 0);
            }
        }
    }
    if(a*t == t && a == iden)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Matrix::ortogonal()
{
    Matrix a(rows, columns);
    Matrix t(rows, columns);
    Matrix iden(rows, columns);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            a.set(i, j, vet_matrix[i][j]);
        }
    }
    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            t.set(i,j,vet_matrix[j][i]);
        }
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(i == j)
            {
                iden.set(i, j, vet_matrix[i][j] = 1);
            }
            else
            {
                iden.set(i, j, vet_matrix[i][j] = 0);
            }
        }
    }
    if(a*t == iden)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int Matrix::potencia(int x)
{
    if(square())
    {
        Matrix c(rows, columns());
        int value = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                for(int k = 0; k < columns; k++)
                {
                    value += vet_matrix[i][k] * vet_matrix[k][j];

                }
                c.set(i, j, value);
                value = 0;
                for(int l = 1; l < 100; l++)
                {
                    c.set(i, j, vet_matrix[i][j] * c.getElement(j,i));
                }

            }
        }
        x=c+c;
    }
        throw std::string("\nNao eh possivel fazer a potencia.\n");
}

