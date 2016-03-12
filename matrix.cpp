#include "matrix.h"
#include <iostream>
void Matrix::define_size(int &lines, int &columns) {

    _l = lines;
    _c = columns;

    _mtx = new int*[columns];

    for (int i = 0; i < lines; i++)
        _mtx[i] = new int[lines];

}

Matrix Matrix::transposta()
{

    Matrix inverso;

    inverso.define_size(_c, _l);

    for(int i = 0; i < _c; i++)
        for(int j = 0; j < _l; j++)
            inverso.set(j,i,_mtx[i][j]);

    return inverso;
}
Matrix Matrix::operator+(Matrix &B){
    if(dimensaoIgual(B)){
        Matrix C;
        C.define_size(_l, _c);
        for(int i = 0; i < _l; i++)
            for(int j = 0; j < _c; j++)
                C.set(i, j, _mtx[i][j] + B.getElement(i, j));
        return C;
    }

    else
        throw  std::string("\nNao eh possivel fazer a soma.\n");

}
Matrix Matrix::operator-(Matrix &B){
    if(dimensaoIgual(B)){
        Matrix C;
        C.define_size(_l,_c);
        for(int i = 0; i < _l; i++)
            for(int j = 0; j < _c; j++)
                C.set(i, j, _mtx[i][j] - B.getElement(i, j));
        return C;
    }

    else
    throw  std::string("\nNao eh possivel fazer a subtracao.\n");
}

bool Matrix::dimensaoIgual(Matrix &B){
    return _l == B.getLine() && _c == B.getColumn();
}
