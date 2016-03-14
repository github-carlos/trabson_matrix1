#include <QCoreApplication>
#include <iostream>
#include "matriz.h"
using namespace std;
int main()
{
    int c;
    int l;
    cout << "\t\t\tM A T R I Z \n\n";
    do
    {
        cout << "Quantidade de colunas: ";
        cin >> c;
    }while(c <= 0);

    do
    {
        cout << "Quantidade de linhas: ";
        cin >> l;
    }while(l <= 0);

    Matriz A(l, c);

    A.fill();

    A.show();

    Matriz result = A.transposed();

    cout << "\t\t\nMatriz invertida\n\n";

    result.show();

    do
    {
        cout << "Quantidade de colunas: ";
        cin >> c;
    }while(c <= 0);

    do
    {
        cout << "Quantidade de linhas: ";
        cin >> l;
    }while(l <= 0);

    Matriz B(l, c);

    B.fill();

    B.show();

    try{
        result = A + B;
        cout << "\n" << "\t\tSoma\n\n";
        result.show();
    }catch(std::string msg){    cout << msg;    }
    cout << "\n";

    return 0;
}

