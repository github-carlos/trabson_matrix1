#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
private:
    int **_mtx;
    int _c;
    int _l;
    bool equalDimension(Matrix B);
    bool columnsA_Equal_LinesB(Matrix &B);
    bool square() {return _c == _l;}
public:
    Matrix():_mtx(0),_c(0), _l(0){}
    ~Matrix() {delete[] _mtx; }
    int getColumn() const { return _c; }
    int getLine() const { return _l; }
    int getElement(int line, int column) const { return _mtx[line][column]; }

    void define_size(int lines, int columns);
    void set(int x, int y, int value) { _mtx[x][y] = value; }

    Matrix operator+(Matrix B);
    Matrix operator-(Matrix B);
    Matrix operator*(Matrix B);
    bool upperTriangular();
    bool lowerTriangular(Matrix &B);

    Matrix operator*(int);
    Matrix transpose(Matrix &B);

    Matrix potencia(Matrix &B);


    bool simetrica(Matrix &B);
    bool identidade(Matrix &B);
    bool igual(Matrix &B);
    bool diferente(Matrix &B);
    bool ortogonal();
    bool permutacao(Matrix &B);


};

#endif // MATRIX_H







