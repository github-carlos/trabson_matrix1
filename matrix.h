#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
private:
    int linhas;
    int colunas;
    int **vet_matriz;

    bool dimensaoIgual( Matriz b) {return linhas == b.getLinhas() && colunas == b.getColunas();}
public:
    Matriz(const int linhas, const int colunas);
    int getColunas() { return colunas; }
    int getLinhas() const { return linhas; }
    int getElement(int &x, int&y) {return vet_matriz[x][y];}
    void set(int x, int y, int valor);
    Matriz inverter();
    void preencher();

    Matriz operator +(Matriz b);

    void mostrar();
};

#endif // MATRIZ_H
