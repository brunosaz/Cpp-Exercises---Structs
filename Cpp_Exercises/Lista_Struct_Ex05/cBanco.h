#ifndef CBANCO_H
#define CBANCO_H
#include <string>

using namespace std;

struct clientes{
    string nome;
    long int cpf;
    int senha;
    float saldo;
};

class cBanco {
public:
    cBanco();
    cBanco(const cBanco& orig);
    virtual ~cBanco();
    
    int pesquisa(clientes cliente[], long int chave, int n);
    void metBolha(clientes cliente[], int n);
    void extrato(clientes cliente);
    void cadastro();
    void gerenciarConta(clientes vetClientes);
    float deposito(float saldo);
    float saque(float saldo);
    void login(clientes cliente[], int n);
    
private:

};

#endif /* CBANCO_H */

