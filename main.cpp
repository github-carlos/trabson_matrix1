#include <QCoreApplication>
#include <iostream>
#include "matriz.h"
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
        cout << "Quantidade de colunas: ";
        cin >> c;
    }while(c <= 0);

    do
    {
        cout << "Quantidade de linhas: ";
        cin >> l;
    }while(l <= 0);

    Matrix A(l, c);

    A.fill();

    show(A);

    Matrix result = A.transposed();

    cout << "\t\t\nMatriz invertida\n\n";

    show(result);

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

    Matrix B(l, c);

    B.fill();

    show(B);

    try{
        result = A + B;
        cout << "\n" << "\t\tSoma\n\n";
        show(result);
    }catch(std::string msg){    cout << msg;    }
    cout << "\n";

    return 0;
}

