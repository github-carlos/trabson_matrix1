#include <QCoreApplication>
#include"matrix.h"
#include<iostream>

using namespace std;

int main()
{
    Matrix A,B,C;
    int aux1,aux2;

    cout<<"Digite a quantidade de linhas de A: ";
    cin>>aux1;
    cout<<"Digite a quantidade de colunas de A: ";
    cin>>aux2;
    A.define_size(aux1,aux2);
    cout<<"Digite a quantidade de linhas de B: ";
    cin>>aux1;
    cout<<"Digite a quantidade de colunas de B: ";
    cin>>aux2;
    B.define_size(aux1,aux2);


    for(int i=0; i<A.getLine(); i++){
        for(int j=0; j<A.getColumn();j++){
            cout<<"Elemento de A: "<<(i+1)<<","<<(j+1)<<": ";
            cin>>aux1;
            A.set(i,j,aux1);
        }
    }
    for(int i=0; i<B.getLine(); i++){
        for(int j=0; j<B.getColumn();j++){
            cout<<"Elemento de B: "<<(i+1)<<","<<(j+1)<<": ";
            cin>>aux1;
            B.set(i,j,aux1);
        }
    }

    C=A+B;

    for(int i=0; i<C.getLine();i++){
        cout<<"\n";
        for(int j=0; j<C.getColumn();j++){
            cout<<C.getElement(i,j)<<"\t";
        }
    }




}
