class Matrix
{
private:
    int **_mtx;
    int _c;
    int _l;

public:
    Matrix():_c(0), _l(0), _mtx(0){}
    ~Matrix() {delete[] _mtx; }
    int getColumn() const { return _c; }
    int getLine() const { return _l; }
    int getElement(int line, int column) const { return _mtx[line][column]; }
    //void setColumn(int &value);
    //void setLine (int &value);
    void define_size(int &lines, int &columns);
    void set(int x, int y, int value) { _mtx[x][y] = value; }
    Matrix operator+(Matrix &B);
    Matrix operator-(Matrix &B);
    Matrix operator*(Matrix &B);
    Matrix operator*(int);
    Matrix transposta();
    Matrix potencia(Matrix &B);

    bool triangularTop(Matrix &B);
    bool triangularBottom(Matrix &B);
    bool simetrica(Matrix &B);
    bool identidade(Matrix &B);
    bool igual(Matrix &B);
    bool diferente(Matrix &B);
    bool ortogonal();
    bool permutacao(Matrix &B);
    bool quadrada() { return _c == _l; }
    bool dimensaoIgual(Matrix &B);

};





























