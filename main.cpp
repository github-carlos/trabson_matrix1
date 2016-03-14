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

    A.preencher();

    A.mostrar();

    Matriz result = A.inverter();

    cout << "\t\t\nMatriz invertida\n\n";

    result.mostrar();

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

    B.preencher();

    B.mostrar();

    try{
        result = A + B;
        cout << "\n" << "\t\tSoma\n\n";
        result.mostrar();
    }catch(std::string msg){    cout << msg;    }
    cout << "\n";

    return 0;
}

