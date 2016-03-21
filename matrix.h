#ifndef MATRIZ_H
#define MATRIZ_H


class Matrix
{
private:
    int rows;
    int columns;
    int **_matrix;
    bool columnsA_Equal_LinesB(Matrix b){return columns == b.getRows();}
    bool square() {return columns == rows;}
    bool equal_dimensions( Matrix b) {return rows == b.getRows() && columns == b.getColumns();}
public:
    Matrix(const int rows, const int columns);
    int getColumns() const { return columns; }
    int getRows() const { return rows; }
    int getElement(int &x, int&y) {return _matrix[x][y];}
    void set(int x, int y, int value);
    void fill();
    Matrix transposed();
    Matrix operator +(Matrix b);
    Matrix operator -(Matrix b);
    Matrix operator *(Matrix b);
    Matrix operator *(int);
    bool operator ==(Matrix &b);
    bool operator !=(Matrix &b);
    bool upperTriangular();
    bool lowerTriangular();
    bool equal(Matrix &b);
    bool identity();
    bool orthogonal();
    bool permutation();
    static bool symmetric(Matrix a);
    int power(int x);
};

#endif // MATRIZ_H
