#ifndef MATRIZ_H
#define MATRIZ_H


class Matrix
{
private:
    int rows;
    int columns;
    int **vet_matrix;

    bool columnsA_Equal_LinesB(Matrix &B);
    bool square() {return columns == rows;}
    bool equal_dimensions( Matrix b) {return rows == b.getRows() && columns == b.getColumns();}


public:
    Matrix(const int rows, const int columns);

    int getColumns() { return columns; }
    int getRows() const { return rows; }
    int getElement(int &x, int&y) {return vet_matrix[x][y];}

    void set(int x, int y, int value);
    void fill();

    Matrix transposed();
    Matrix operator +(Matrix b);
    Matrix operator-(Matrix b);
    Matrix operator*(Matrix b);
    Matrix operator*(int);
    Matrix potencia(Matrix &b);

    bool simetrica(Matrix &b);
    bool identidade(Matrix &b);
    bool igual(Matrix &b);
    bool diferente(Matrix &b);
    bool ortogonal();
    bool permutacao(Matrix &b);
    bool upperTriangular();
    bool lowerTriangular(Matrix &b);


};

#endif // MATRIZ_H
