#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
private:
    int rows;
    int columns;
    int **vet_matrix;

    bool equal_dimensions( Matriz b) {return rows == b.getRows() && columns == b.getColumns();}
public:
    Matriz(const int rows, const int columns);
    int getColumns() { return columns; }
    int getRows() const { return rows; }
    int getElement(int &x, int&y) {return vet_matrix[x][y];}
    void set(int x, int y, int value);
    Matriz transposed();
    void fill();

    Matriz operator +(Matriz b);

    void show();
};

#endif // MATRIZ_H
