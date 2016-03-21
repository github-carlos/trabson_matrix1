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
    int po;
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

    cout<<"Digite uma potencia.\n";
    cin>>po;

    try{
        result = A * B;
        cout << "\n" << "\t\tSubtracao\n\n";
        show(result);
        cout<<"potencia da matriz A: "<<A.power(po)<<"\n";
    }catch(std::string msg){    cout << msg;    }
    cout << "\n";
    if(Matrix::symmetric(A))
    {
        cout << "Matriz Simetrica!\n";
    }
    else
    {
        cout << "Nao eh uma Matriz Simetrica!\n";
    }
    if(A.identity())
    {
        cout << "Matriz identidade!\n";
    }
    else
    {
        cout << "Nao eh uma Matriz identidade!\n";
    }
    if(A.orthogonal() == true)
    {
        cout<<"Matriz ortogonal!\n";
    }
    else
    {
        cout<<"Nao eh ortogonal!\n";
    }
    if(A.permutation() == true)
    {
        cout<<"Matriz permutacao!\n";
    }
    else
    {
        cout<<"Nao eh permutacao!\n";
    }

    return 0;
}
