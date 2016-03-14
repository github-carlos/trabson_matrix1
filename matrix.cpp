#include "matriz.h"
#include <iostream>
using namespace std;

Matriz::Matriz(const int linhas , const int colunas )
{

    this->linhas = linhas;
    this->colunas = colunas;
    vet_matriz = new int*[this->colunas];//alocando colunas


    for(int i = 0; i < this->colunas; i++)
        vet_matriz[i] = new int[this->linhas]; //alocando linhas
}
void Matriz::set(int x, int y, int valor) //
{
    vet_matriz[x][y] = valor;
}

Matriz Matriz::inverter()
{
    Matriz inverso(colunas, linhas);

    for(int i = 0; i < colunas; i++)
        for(int j = 0; j < linhas; j++)
            inverso.set(j,i,vet_matriz[i][j]);

    return inverso;
}
void Matriz::preencher()
{
    int k = 0;
    for(int i = 0; i < linhas ; i++)
    {
        for(int j = 0; j < colunas; j++){
            cout << "[" << i << "] " << "[" << j << "] = ";
            cin >> k;
            vet_matriz[j][i] = k;
        }
    }
}

Matriz Matriz::operator +(Matriz b)
{
    if(dimensaoIgual(b))
    {
        Matriz c(linhas,colunas);

        for(int i = 0; i < linhas; i++)
        {
            for(int j = 0; j < colunas; j++)
            {
                c.set(i, j, vet_matriz[i][j] + b.getElement(i, j));
            }
        }
        return c;
    }

    throw std::string("\nNao eh possivel fazer esta soma!");

}

void Matriz::mostrar()
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)

            cout << vet_matriz[j][i] << "\t";

        cout << endl;
    }
}
