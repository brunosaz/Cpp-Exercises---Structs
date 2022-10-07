#ifndef CIMC_H
#define CIMC_H
#include <iostream>
#include <string>

using namespace std;

struct pessoas{
    string nome, sexo;
    long int cpf;
    float altura, peso, imc;
};

class cIMC {
public:
    cIMC();
    cIMC(const cIMC& orig);
    virtual ~cIMC();
    void lerDados();
    float calcIMC(float altura, float peso);
    int localizar(pessoas pessoa[], long int cpf, int n);
    void exibir(pessoas pessoa);
    
private:

};

#endif /* CIMC_H */

