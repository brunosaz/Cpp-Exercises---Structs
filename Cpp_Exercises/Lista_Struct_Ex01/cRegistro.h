#ifndef CREGISTRO_H
#define CREGISTRO_H
#include <iostream>
#include <string>

using namespace std;

struct alunos{
    float n1, n2, media;
    string nome, mat;
};

class cRegistro {
public:
    cRegistro();
    cRegistro(const cRegistro& orig);
    virtual ~cRegistro();
    void lerDados();
    void exibir(alunos aluno, int n, int i);
    float media(float n1, float n2);
    
private:

};

#endif /* CREGISTRO_H */

