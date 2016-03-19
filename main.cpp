#include <QCoreApplication>
#include <iostream>
#include "matrix.h"
using namespace std;
void show(Matrix a)
{
    for(int i = 0; i < a.getRows(); i++)
    {
        for(int j = 0; j < a.getColumns(); j++)

            cout << a.getElement(i, j) << "\t";

        cout << endl;
    }
}
int main()
{
    int c;
    int l;
    cout << "\t\t\tM A T R I Z \n\n";
    do
    {
        cout << "Quantidade de linhas: ";
        cin >> l;
    }while(l <= 0);

    do
    {
        cout << "Quantidade de colunas: ";
        cin >> c;
    }while(c <= 0);

    Matrix A(l, c);

    A.fill();

    show(A);

    Matrix result = A.transposed();

    cout << "\t\t\nMatriz transposta\n\n";

    show(result);

    do
    {
        cout << "Quantidade de linhas: ";
        cin >> l;
    }while(l <= 0);

    do
    {
        cout << "Quantidade de colunas: ";
        cin >> c;
    }while(c <= 0);

    Matrix B(l, c);

    B.fill();

    show(B);

    try{
        result = A * 2;
        cout << "\n" << "\t\tSubtracao\n\n";
        show(result);
    }catch(std::string msg){    cout << msg;    }
    cout << "\n";
    if(Matrix::simetrica(A))
    {
        cout << "Matriz Simetrica!\n";
    }
    else
    {
        cout << "Nao eh uma Matriz Simetrica!\n";
    }
    if(A.identidade())
    {
        cout << "Matriz identidade!\n";
    }
    else
    {
        cout << "Nao eh uma Matriz identidade!\n";
    }
    if(A.ortogonal() == true)
    {
        cout<<"Matriz ortogonal!\n";
    }
    else
    {
        cout<<"Nao eh ortogonal!\n";
    }
    if(A.permutacao() == true)
    {
        cout<<"Matriz permutacao!\n";
    }
    else
    {
        cout<<"Nao eh permutacao!\n";
    }

    return 0;
}
