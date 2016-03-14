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

    matriz A(l, c);

    A.preencher();

    A.mostrar();

    matriz result = A.inverter();

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

    matriz B(l, c);

    B.preencher();

    B.mostrar();

    try{
        result = A + B;
        result.mostrar();
    }catch(std::string msg){    cout << msg;    }
    cout << "\n";
    
    return 0;
}

