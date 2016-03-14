#ifndef MATRIZ_H
#define MATRIZ_H


class matriz
{
private:
    int linhas;
    int colunas;
    int **vet_matriz;

    bool dimensaoIgual( matriz b) {return linhas == b.getLinhas() && colunas == b.getColunas();}
public:
    matriz(const int linhas, const int colunas);
    int getColunas() { return colunas; }
    int getLinhas() const { return linhas; }
    int getElement(int &x, int&y) {return vet_matriz[x][y];}
    void set(int x, int y, int valor);
    matriz inverter();
    void preencher();

    matriz operator +(matriz b);

    void mostrar();
};

#endif // MATRIZ_H
