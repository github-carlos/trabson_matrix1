#ifndef MATRIZ_H
#define MATRIZ_H


class Matrix
{
private:
    int rows;
    int columns;
    int **vet_matrix;

    bool columnsA_Equal_LinesB(Matrix b){return columns == b.getRows();}
    bool square() {return columns == rows;}
    bool equal_dimensions( Matrix b) {return rows == b.getRows() && columns == b.getColumns();}


public:
    Matrix(const int rows, const int columns);

    int getColumns() const { return columns; }
    int getRows() const { return rows; }
    int getElement(int &x, int&y) {return vet_matrix[x][y];}

    void set(int x, int y, int value);
    void fill();

    Matrix transposed();
    Matrix operator +(Matrix b);
    Matrix operator-(Matrix b);
    Matrix operator*(Matrix b);
    Matrix operator*(int);
    bool operator ==(Matrix &b);
    bool operator !=(Matrix &b);
    bool upperTriangular();
    bool lowerTriangular();
    bool igual(Matrix &b);
    bool identidade();
    bool ortogonal();
    bool permutacao();
    static bool simetrica(Matrix a);


    int potencia(int x);






};

#endif // MATRIZ_H
