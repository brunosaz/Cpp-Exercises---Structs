#ifndef CPRODUTO_H
#define CPRODUTO_H
#include <iostream>
#include <string>

using namespace std;

struct produtos{
    float preco;
    string prod;
    int cod;
};

class cProduto {
public:
    cProduto();
    cProduto(const cProduto& orig);
    virtual ~cProduto();
    
    void cadastro();
    void printList(produtos produto[], int n);
    int pesquisa(produtos produto[], int cod, int n);
    void metBolha(produtos produto[], int n);
    void exibir(produtos produto); 
private:

};

#endif /* CPRODUTO_H */

