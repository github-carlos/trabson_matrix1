#include "matriz.h"
#include <iostream>
using namespace std;

Matriz::Matriz(const int rows , const int columns )
{

    this->rows = rows;
    this->columns = columns;
    vet_matrix = new int*[this->columns];//Columns allocation


    for(int i = 0; i < this->columns; i++)
        vet_matrix[i] = new int[this->rows]; //Rows allocation
}
void Matriz::set(int x, int y, int value) //
{
    vet_matrix[x][y] = value;
}

Matriz Matriz::transposed()
{
    Matriz aux(columns, rows);

    for(int i = 0; i < columns; i++)
        for(int j = 0; j < rows; j++)
            aux.set(j,i,vet_matrix[i][j]);

    return aux;
}
void Matriz::fill()
{
    int k = 0;
    for(int i = 0; i < rows ; i++)
    {
        for(int j = 0; j < columns; j++){
            cout << "[" << i << "] " << "[" << j << "] = ";
            cin >> k;
            vet_matrix[j][i] = k;
        }
    }
}

Matriz Matriz::operator +(Matriz b)
{
    if(equal_dimensions(b))
    {
        Matriz c(rows, columns);

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

void Matriz::show()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)

            cout << vet_matrix[j][i] << "\t";

        cout << endl;
    }
}
